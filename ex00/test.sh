#!/bin/bash

CONVERTER='./convert'
RED='\033[0;31m'
GREEN='\033[0;32m'
NORMAL='\033[0m'

function test()
{
	printf "\n$GREEN$CONVERTER $1$NORMAL\n"
	$CONVERTER $1
}

function wrongtest()
{
	printf "\n$RED$CONVERTER $1$NORMAL\n"
	$CONVERTER $1
}

printf "\n$GREEN$===make===$NORMAL\n"
make

printf "\n$RED===WRONG ARGUMENTS===\n$NORMAL"
wrongtest
wrongtest ".f"
wrongtest "-.f"
wrongtest "7f"
wrongtest "7.77.7"
wrongtest "-7.12f1"


printf "\n$GREEN===CORRECT ARGUMENTS===\n$NORMAL"
test "0"
test "nan"
test "42.0f"
test "nanf"
test "inf"
test "inff"
test "-inf"
test "-inff"
test "+inf"
test "+inff"
test "'c'"
test "'0'"
test "0.0f"
test ".0f"
test "0.f"
test "0."
test "42.00001f"
test "42.12"
test "-42.5"
test "42000000000000000000000000000000000000.42"
test "420000000000000000000000000000000000000.42"
test "420000000000000000000000000000000000000.42f"
test "2147483648"
test "2147483648.1"
test "-2147483649"
test "-2147483648"

printf "\n$GREEN$===make fclean===$NORMAL\n"
make fclean
