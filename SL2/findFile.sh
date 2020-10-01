#!/usr/local/bin/bash

if test -f $1
then
  echo ===================================================
  echo $1 Contents:
  echo ===================================================
  cat $1
  echo ===================================================
  echo sample.txt Contents:
  echo ===================================================
  grep -i "Record" $1 | cat>>sample.txt
  cat sample.txt
  echo ===================================================
else
  echo File not Found
fi
