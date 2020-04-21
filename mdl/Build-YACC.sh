#!/bin/bash

# Linux
# yum install bison

# Mac OS X
# port install bison # MacPorts

# Windows
# choco install winflexbison3 # chocolatey

DIR="$(dirname "$0")"

bison -y -o ${DIR}/../yyparser.inl -p mdl_yy ${DIR}/parser.y -L C 
