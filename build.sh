#!/usr/bin/env bash

if [ -f min ]; then
    rm -f main
fi

gcc main.c lists.c -o main -lm

./main
