#!/bin/bash

set -e

# To build your solution before testing:
#g++ -O2 -DLOCAL -std=c++11 main.cpp -o main


while [[ true ]]; do
  ./gen # Run generator
  ./solution # Run your solution
  python3 kek.py # Run brute or true solution
  ./check # Run checker (return not zero if answers are different)
  #echo "ok";
done
