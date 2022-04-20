#!/bin/bash
FILE=cliente
make $FILE
if test -f "./$FILE"; then
	valgrind --tool=helgrind --log-file=a.out ./$FILE
fi
