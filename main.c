#include <stdio.h>
#include <stdlib.h>
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

int main() {
    List list;
    list = init_list();
    insert_node(&list, "asdf");
    insert_node(&list, "123");
    insert_node(&list, "zxcv");
    return 0;
}
