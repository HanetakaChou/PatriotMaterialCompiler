#!/bin/bash

DIR="$(dirname "$0")"

flex -X -o ${DIR}/MDLScanner.inl ${DIR}/MDLScanner.l   
