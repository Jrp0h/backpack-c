#!/bin/bash


if [ ! -d "build" ]; then
  mkdir build
fi

cd build

cmake ..

if [ -f "../compile_commands.json" ]; then
  rm ../compile_commands.json
fi

cp compile_commands.json ../compile_commands.json 
