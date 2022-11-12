#!/bin/bash

touch equal.csv
touch inequal.csv
echo "file1,file2" > equal.csv
echo "file1,file2" > inequal.csv
for tmp_dir in $(ls ./workdir); do
    dir="workdir/"$tmp_dir
    #dir=/workdir/input0
    declare -A dict
    for file1 in $dir/*.txt; do
        for file2 in $dir/*.txt; do
            if [ $file1 != $file2 ] && [ ! -v dict[$file2] ]
            then 
                tmp1=${file1%input*}
                tmp11=${tmp1##*/}
                tmp111="input/dir/"$tmp11".cpp"
                tmp2=${file2%input*}
                tmp22=${tmp2##*/}
                tmp222="input/dir/"$tmp22".cpp"
                if diff $file1 $file2 > /dev/null; then
                    echo $tmp111","$tmp222 >> equal.csv
                else
                    echo $tmp111","$tmp222 >> inequal.csv
                fi
            fi
        done
        dict[$file1]=1
    done
done