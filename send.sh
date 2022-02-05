#!/bin/bash

PID=$(ps -a | grep server | grep -v grep | grep -v defunct | awk '{print $1}')
MESSAGE="$1"
./client $PID "$MESSAGE"
