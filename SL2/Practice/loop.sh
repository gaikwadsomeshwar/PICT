#!/usr/local/bin/bash

echo $BASH_VERSION

for i in 1 2 3 4 5
do
  echo -n "$i "
done

echo
echo

for num in {1..10..2}
do
  echo -n "$num "
done

echo
echo

for command in ls date
do
  echo "-----------$command-----------"
  $command
done

echo
echo

n=1
while [ $n -le 10 ]
do
  echo -n "$n "
  n=$(( n+1 ))
done

echo
echo

n=1
while (( $n <= 10 ))
do
  echo -n "$n "
  n=$(( ++n ))
done

echo
echo

n=0
m=0
while (( $n <= 9 ))
do
  m=0
  while (( $m <= $n ))
  do
    echo -n $(( n-m ))
    m=$(( m+1 ))
  done
  echo
  n=$(( n+1 ))
done

echo
echo

n=1
until [ $n -ge 10 ]
do
  echo -n "$n "
  n=$(( n+1 ))
done

echo
echo

vehicle="truck"
case $vehicle in
  "car" )
    echo "Rent of $vehicle is 100 dollar";;
  "van" )
    echo "Rent of $vehicle is 80 dollar";;
  "bicycle" )
    echo "Rent of $vehicle is 5 dollar";;
  "truck" )
    echo "Rent of $vehicle is 700 dollar";;

  "*" )
    echo "Unkown Vehicle";;
esac

echo
echo

select name in Rachana Someshwar Shreyas
do
  echo $name
  break
done

echo
echo

read -p "Enter vehicle type: " vehicle
case $vehicle in
  "car" )
    echo "Rent of $vehicle is 100 dollar";;
  "van" )
    echo "Rent of $vehicle is 80 dollar";;
  "bicycle" )
    echo "Rent of $vehicle is 5 dollar";;
  "truck" )
    echo "Rent of $vehicle is 700 dollar";;
  "*" )
    echo "Unkown Vehicle";;
esac
