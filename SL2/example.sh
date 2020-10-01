#!/usr/local/bin/bash

read -p "Ramesh's Basic Salary: " sal
gsal=$(( sal + sal * 40 / 100 + sal * 20 / 100 ))
echo "Ramesh's Basic Salary      : $sal"
echo "Ramesh's Dearness Allowance: $(( sal * 40 / 100 ))"
echo "Ramesh's Rent Allowance    : $(( sal * 20 / 100 ))"
echo "Ramesh's Gross Salary is   : $gsal"
