#!/bin/bash

# Linux
# yum install bison

# Mac OS X
# port install bison # MacPorts

# Windows
# choco install winflexbison3 # chocolatey

DIR="$(dirname "$0")"

bison -y -L C ${DIR}/parser.y -o ${DIR}/../yyparser.inl