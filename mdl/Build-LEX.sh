#!/bin/bash

DIR="$(dirname "$0")"

flex -X -o ${DIR}/mdl_lllexer.inl ${DIR}/mdlscanner.l   
