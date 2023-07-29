#!/bin/bash

mkdir -p .build
cd .build
cmake ..
make
./check_test_cases
cd ..

