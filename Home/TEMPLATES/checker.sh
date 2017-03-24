#!/bin/bash

set -e

#g++ -O2 -DLOCAL -std=c++11 main.cpp -o main
while [[ true ]]; do
  ./gen
  ./itmo
  python3 kek.py
  ./check
  #echo "ok";
done