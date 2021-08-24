#!/bin/sh

#
# Installation: chmod +x ./make.sh
# Usage: ./make.sh
#

# shell variables: declare and assign value
GCC_OPTIONS="-g -ansi -pedantic -Wall"
TARGET1="cc_encrypt"
TARGET2="cc_decrypt"


echo "gcc $GCC_OPTIONS $TARGET1.c -o $TARGET1"
gcc $GCC_OPTIONS $TARGET1.c -o $TARGET1

echo "gcc $GCC_OPTIONS $TARGET2.c -o $TARGET2"
gcc $GCC_OPTIONS $TARGET2.c -o $TARGET2

exit 0
