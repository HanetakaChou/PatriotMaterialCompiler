#!/bin/bash

DIR="$(dirname "$0")"

c++ ${DIR}/../main.cpp -g2 -O0 -fPIE -fPIC -pie -o ${DIR}/../a.out  #-g0 -O3 -DNDEBUG=1