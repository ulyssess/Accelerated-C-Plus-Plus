#!/bin/bash

test()
{
    echo $1
    echo -n "list   " && (time ./list_mode/grade < test_$1.txt) 2>&1 |grep real | awk '{print $2}'
    echo -n "vector " && (time ./vector_mode/grade < test_$1.txt) 2>&1 |grep real | awk '{print $2}'
    echo
}

test 10
test 100
test 1000
test 10000
test 20000
