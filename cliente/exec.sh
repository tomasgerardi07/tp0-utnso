#!/bin/bash
FILE=cliente
make $FILE
if test -f "./$FILE"; then
	./$FILE
fi
