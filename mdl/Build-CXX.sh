#!/bin/bash

DIR="$(dirname "$0")"

CFLAGS="-g2 -O0 -fPIE -fPIC" #-g0 -O3 -DNDEBUG=1
LDFLAGS="-pie -Wl,--no-undefined"

clang -c ${DIR}/../yylexer.c ${CFLAGS} -o ${DIR}/../yylexer.o
clang -c ${DIR}/../yyparser.c ${CFLAGS} -o ${DIR}/../yyparser.o
clang++ -c ${DIR}/../PTInputStream.cpp ${CFLAGS} -o ${DIR}/../PTInputStream.o
clang++ -c ${DIR}/../main.cpp ${CFLAGS} -o ${DIR}/../main.o
clang++ ${DIR}/../yylexer.o ${DIR}/../yyparser.o ${DIR}/../main.o ${DIR}/../PTInputStream.o ${LDFLAGS} -o ${DIR}/../a.out 

# ${DIR}/../PTInputStream.cpp ${DIR}/../yylexer.c