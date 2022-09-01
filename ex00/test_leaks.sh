#!/bin/bash

./test.sh "leaks --atExit -- " > test_leaks.log
cat test_leaks.log | grep "leaks for"
rm test_leaks.log
