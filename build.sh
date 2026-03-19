#!/bin/bash

gcc -DGS_STANDALONE \
    -I./src \
    -c src/gsc.c -o build/gsc.o

gcc -DGS_STANDALONE \
    -I./src \
    -c src/module.c -o build/module.o

gcc -DGS_STANDALONE \
    -I./src \
    -c lib/fs.c -o build/fs.o

gcc -DGS_STANDALONE \
    build/gsc.o build/module.o build/fs.o \
    -o goscript -lm

echo "Compilation terminée: ./goscript"
