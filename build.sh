#!/bin/bash
gcc src/module.c src/fe.c -DFE_STANDALONE -O3 -o fe -Wall -Wextra -std=c99 -pedantic
