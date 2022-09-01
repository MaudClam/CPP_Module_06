#!/bin/bash

./test.sh "valgrind " > test_valgrind.log
cat test_valgrind.log | grep "in use at exit:"
rm test_valgrind.log
