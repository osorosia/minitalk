#!/bin/bash
./server 1>output.tmp 2>/dev/null &
ps -a | grep server | grep -v grep | grep -v defunct
PID=$(ps -a | grep server | grep -v grep | grep -v defunct | awk '{print $1}')
MESSAGE=$1
./client $PID $MESSAGE
sleep 1
kill $PID
echo ----------------------------------------------------------
cat output.tmp
echo
echo ----------------------------------------------------------
