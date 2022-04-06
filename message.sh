#!/bin/bash

PID=$(ps -a | grep server | grep -v grep | grep -v defunct | awk '{print $1}')
MESSAGE="$1"
echo "send to: $PID"
./client $PID "$MESSAGE"
