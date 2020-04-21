#!/bin/bash

DIR="$(dirname "$0")"

flex -X -o ${DIR}/../yylexer.inl ${DIR}/scanner.l   
