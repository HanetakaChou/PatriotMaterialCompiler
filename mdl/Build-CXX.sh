#!/bin/bash

DIR="$(dirname "$0")"

CFLAGS="-g2 -O0 -fPIE -fPIC" #-g0 -O3 -DNDEBUG=1
LDFLAGS="-pie -Wl,--no-undefined"

clang -c ${DIR}/MDLScanner.c ${CFLAGS} -o ${DIR}/../MDLScanner.o
clang -c ${DIR}/MDLScanner.cpp ${CFLAGS} -o ${DIR}/../MDLScanner.cpp.o
clang -c ${DIR}/MDLParser.c ${CFLAGS} -o ${DIR}/../MDLParser.o
clang -c ${DIR}/MDLParser.cpp ${CFLAGS} -o ${DIR}/../MDLParser.cpp.o
clang++ -c ${DIR}/PT_MatC_Stream.cpp ${CFLAGS} -o ${DIR}/../PT_MatC_Stream.o
clang++ -c ${DIR}/MDLFrontend.cpp ${CFLAGS} -o ${DIR}/../MDLFrontend.o
clang++ -c ${DIR}/../main.cpp ${CFLAGS} -o ${DIR}/../main.o
clang++ ${DIR}/../MDLScanner.o ${DIR}/../MDLScanner.cpp.o ${DIR}/../MDLParser.o ${DIR}/../MDLParser.cpp.o ${DIR}/../main.o ${DIR}/../PT_MatC_Stream.o ${DIR}/../MDLFrontend.o ${LDFLAGS} -o ${DIR}/../a.out 

# ${DIR}/../PTInputStream.cpp ${DIR}/../yylexer.c