#!/bin/bash

os=$(uname)

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

    ../server 1>./actual/$filename 2>/dev/null &

    PID="$(ps -a | grep server | grep -v grep | grep -v defunct | awk '{print $1}')"
    MESSAGE="$(cat ./expected/$filename)"
    ../client "$PID" "$MESSAGE"

    ./usleep 10000
    kill $PID
    wait
    
    diff --text -U 0 ./actual/$filename ./expected/$filename > ./diff/$filename
    result=$?
    if [ $result -eq 0 ]; then
        echo "$filename: OK"
        rm -f ./diff/$filename
    else
        echo "$filename: KO!!!!!!!"
    fi
}

# tests
assert aaaaa
assert aaaaa_nl
