#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    const char* val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

List init_list() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

void insert_node(List* list, const char string[]) {
    Node* node = malloc(sizeof(Node));
    node->val = string;
    if (list->head == NULL) {
        node->prev = NULL;
        node->next = NULL;

        list->head = node;
        list->tail = node;
        return;
    }

    Node* curr = list->head;
    while(curr->next != NULL) {
        curr = curr->next;
    }

    node->prev = curr;
    node->next = NULL;

    curr->next = node;
    list->tail = node;
}

Node* get_node(List* list, int index) {
    Node* curr = list->head;
    for(int i = 0; i < index; i++) {
        if (curr->next == NULL) {
            return NULL;
        }

        curr = curr->next;
    }

    return curr;
}

// returns true if operation succesful, returns false otherwise
bool delete_node(List* list, int index) {
    Node* curr = list->head;

    // special case for the head
    if (index == 0) {
        if (curr->next == NULL) {
            list->head = NULL;
            list->tail = NULL;
            free(curr);
            return true;
        }

        Node* newHead = curr->next;
        newHead->prev = NULL;
        list->head = newHead;
        free(curr);
        return true;
    }

    for(int i = 0; i < index-1; i++) {
        if (curr->next == NULL) {
            return false;
        }

        curr = curr->next; 
    }

    // checking if node that we intend to delete exists
    if (curr->next == NULL) {
        return false;
    }
    
    Node* toDelete = curr->next;

    if (toDelete == list->tail) {
        curr->next = NULL;
        list->tail = curr;
        free(toDelete);
        return true;
    }

    curr->next = toDelete->next;
    (toDelete->next)->prev = curr;
    free(toDelete);
    return true;
}

int main() {
    List list;
    list = init_list();
    insert_node(&list, "asdf");
    insert_node(&list, "123");
    insert_node(&list, "zxcv");
    bool res = delete_node(&list, 0);
    printf("%d", res);
    return 0;
}
