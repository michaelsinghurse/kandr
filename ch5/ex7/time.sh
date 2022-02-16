#!/bin/bash

echo "ALLOC.OUT:"
time cat text.txt | ./alloc.out > /dev/null

echo ""
echo "ARRAY.OUT:"
time cat text.txt | ./array.out > /dev/null
