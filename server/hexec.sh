#!/bin/bash
FILE=server
make $FILE
if test -f "./$FILE"; then
	valgrind --tool=helgrind --log-file=a.out ./$FILE
fi
