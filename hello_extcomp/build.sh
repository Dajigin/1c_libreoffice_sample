#!/bin/bash
./clean.sh
cmake -S. -B./tmp
cd ./tmp
make
