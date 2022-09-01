#!/bin/bash

BOLD='\033[1m'
NORMAL='\033[0m'

printf $BOLD"\n./test.sh \"valgrind \" 2> test_valgrind.log\n"$NORMAL
./test.sh "valgrind " 2> test_valgrind.log

printf $BOLD"\ncat test_valgrind.log | grep \"in use at exit:\"\n\n"$NORMAL
cat test_valgrind.log | grep "in use at exit:"

printf $BOLD"\nrm test_valgrind.log\n\n"$NORMAL
rm test_valgrind.log
