#!/bin/bash

# init
rm -rf actual
mkdir actual
rm -rf output
mkdir output
rm -rf diff
mkdir diff

gcc -o usleep usleep.c

assert() {
    filename=$1

    ../server > ./output/$filename &

    PID=$(ps -a | grep server | grep -v grep | grep -v defunct | awk '{print $1}')
    MESSAGE=$(cat ./expected/$filename)
    ../client $PID $MESSAGE

    ./usleep 10000
    kill $PID
    cat ./output/$filename | sed -e '1d' > ./actual/$filename

    diff --text ./actual/$filename ./expected/$filename > ./diff/$filename
    result=$?
    if [ $result -eq 0 ]; then
        echo "$filename: OK"
        rm -f ./diff/$filename
    else
        echo -e "\e[31m$filename: KO\e[m"
    fi
}

# tests
assert simple
