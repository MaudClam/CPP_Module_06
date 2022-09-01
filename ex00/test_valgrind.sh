#!/bin/bash

BOLD='\033[1m'
NORMAL='\033[0m'

printf $BOLD"./test.sh \"valgrind \" 2> test_valgrind.log\n"$NORMAL
./test.sh "valgrind " 2> test_valgrind.log

printf $BOLD"cat test_valgrind.log | grep \"in use at exit:\"\n"$NORMAL
cat test_valgrind.log | grep "in use at exit:"

printf $BOLD"rm test_valgrind.log"\n"$NORMAL
rm test_valgrind.log
