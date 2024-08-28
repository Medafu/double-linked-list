@echo off
pushd build
cl ../main.c /EHsc /Zi
popd
