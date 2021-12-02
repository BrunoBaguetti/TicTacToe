#!/bin/bash

cd ~/Training/setup/
rm -rf build
mkdir build
cd build
cmake ..
make
mv TicTacToe_run ../