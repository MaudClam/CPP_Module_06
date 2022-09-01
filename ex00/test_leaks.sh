#!/bin/bash

BOLD='\033[1m'
NORMAL='\033[0m'

printf $BOLD"./test.sh \"leaks --atExit -- \" > test_leaks.log\n"$NORMAL
./test.sh "leaks --atExit -- " > test_leaks.log

printf $BOLD"cat test_leaks.log | grep \"leaks for\"\n"$NORMAL
cat test_leaks.log | grep "leaks for"

printf $BOLD"rm test_leaks.log\n"$NORMAL
rm test_leaks.log
