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

    ../server 1>output.tmp 2>/dev/null &

    PID="$(ps -a | grep server | grep -v grep | grep -v defunct | awk '{print $1}')"
    MESSAGE="$(cat ./expected/$filename)"
    ../client "$PID" "$MESSAGE"

    ./usleep 10000
    kill $PID
    wait
    
    cat output.tmp | sed -e '1d' > ./actual/$filename
    diff --text -U 0 ./actual/$filename ./expected/$filename > ./diff/$filename
    result=$?
    if [ $result -eq 0 ]; then
        echo "$filename: OK"
        rm -f ./diff/$filename
    else
        echo "$filename: KO!!!!!!!"
    fi
}

timer() {
    filename=$1

    start_time=`date +%s`
    assert $1
    end_time=`date +%s`
    
    run_time=$((end_time - start_time))
    echo "  - time: $run_time"
}

# mandatory
make re -C .. &> /dev/null
timer big_10000
