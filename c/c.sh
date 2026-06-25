#!/bin/bash

echo "====== Compilation in progress ======"
gcc $1

echo "====== Exectuion in progress ======"
./a.out

echo "====== Cleaning up directory ======"
rm a.out