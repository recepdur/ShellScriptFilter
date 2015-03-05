#!/bin/bash
 
recursivelyList() {
 for path in $1/*;do
    if [ -d $path ];then        # list directories
        #echo $path
        recursivelyList $path $2
    elif [ -f $path ]; then     # list files
        echo $path
    /home/recep/src/filter $2 $path
    echo ""
    fi
 done
}
 
recursivelyList $1 $2
