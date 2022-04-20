#!/bin/bash
FILE=server
make $FILE
if test -f "./$FILE"; then
	valgrind --tool=memcheck --leak-check=yes --show-possibly-lost=no --num-callers=20 ./$FILE
fi
