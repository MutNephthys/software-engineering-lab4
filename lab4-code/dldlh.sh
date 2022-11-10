#!/bin/bash

mkdir -p ./workdir 

for input in ./OJinput/*.txt; do
    mkdir -p ./workdir/$(basename ${input%.txt})
    for fcpp in ./input/dir/*.cpp; do
        g++ $fcpp -o ./workdir/$(basename ${input%.txt})/$(basename ${fcpp%.cpp})
        ./workdir/$(basename ${input%.txt})/$(basename ${fcpp%.cpp}) <$input >./workdir/$(basename ${input%.txt})/$(basename ${fcpp%.cpp})$(basename ${input%.txt}).txt
    done
done