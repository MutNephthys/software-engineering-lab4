#!/bin/bash

touch equal.csv
touch inequal.csv
echo "file1,file2" > equal.csv
echo "file1,file2" > inequal.csv
declare -A dict_equal
declare -A dict_inequal
for tmp_dir in $(ls ./workdir); do
    dir="workdir/"$tmp_dir
    #dir=/workdir/input0
    declare -A dict_nonrepeatable
    for file1 in $dir/*.txt; do
        for file2 in $dir/*.txt; do
            if [ $file1 != $file2 ] && [ ! -v dict_nonrepeatable[$file2] ]
            then 
                tmp1=${file1%input*}
                tmp11=${tmp1##*/}
                tmp111="input/dir/"$tmp11".cpp"
                tmp2=${file2%input*}
                tmp22=${tmp2##*/}
                tmp222="input/dir/"$tmp22".cpp"
                if diff $file1 $file2 > /dev/null; then
                    if [ ! -v dict_equal[$tmp111","$tmp222] ]
                    then
                        dict_equal[$tmp111","$tmp222]=1
                        #echo $tmp111","$tmp222"    1"
                    fi
                else
                    if [ ! -v dict_inequal[$tmp111","$tmp222] ]
                    then
                        echo $tmp111","$tmp222 >> inequal.csv
                        dict_inequal[$tmp111","$tmp222]=1
                    fi
                    if [ -v dict_equal[$tmp111","$tmp222] ]
                    then 
                        dict_equal[$tmp111","$tmp222]=0
                        #echo $tmp111","$tmp222"    0"

                    fi
                fi
            fi
        done
        dict_nonrepeatable[$file1]=1
    done
done
for key in $(echo ${!dict_equal[*]})
do
    if [ dict_equal[$key]==1 ]
    then
        echo $key >> equal.csv
    fi
done