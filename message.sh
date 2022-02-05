#!/bin/bash

ARG=$(ps -a | grep server | grep -v grep | awk '{print $1}')
STR=$1
./client $ARG $STR
