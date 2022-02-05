#!/bin/bash

ARG=$(ps -a | grep server | awk '{print $1}')
STR=$1
./client $ARG $STR
