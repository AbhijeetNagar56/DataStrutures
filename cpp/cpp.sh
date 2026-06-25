#!/bin/bash

echo "====== Compilation in progress ======"
g++ $1

echo "====== Exectuion in progress ======"
./a.out

echo "====== Cleaning up directory ======"
rm a.out