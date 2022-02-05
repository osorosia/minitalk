#!/bin/bash
if [ ! -f ./.test/usleep ]; then
    gcc -o ./.test/usleep ./.test/usleep.c
fi

./server &>output.tmp &

ps -a | grep server | grep -v grep | grep -v defunct
PID=$(ps -a | grep server | grep -v grep | grep -v defunct | awk '{print $1}')
MESSAGE=$1
./client $PID $MESSAGE

./.test/.usleep 100000
kill $PID
wait

echo ----------------------------------------------------------
cat output.tmp
echo
echo ----------------------------------------------------------
