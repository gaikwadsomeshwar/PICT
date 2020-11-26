#!/usr/local/bin/bash

if [ $# -eq 2 ]
then
  sum=` echo "$1+$2" | bc `
  echo Sum: $sum
  exit 1
else
  echo Incorrect number of Arguements
  exit 1
fi
