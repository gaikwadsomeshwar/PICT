#!/usr/local/bin/bash

filename=AttendanceRecord.txt

create() {

  read -p "Enter File Name: " filename
  echo
  if test -f $filename
  then
    echo $filename Exists!
    echo
    cat $filename
    echo ================================
    echo -n Word Count:
    wc -w $filename
    echo "================================"
  else
    echo Creating a new file!
    touch $filename
    echo "================================" >>$filename
    echo "        Attendance Record       " >>$filename
    echo "================================" >>$filename
    echo -e "Roll No \t Name \t Class \t Attendance" >>$filename
    echo "================================" >>$filename
    echo -n Word Count:
    wc -w $filename
    echo "================================"
  fi
}

insert() {

  read -p "Roll No   : " rollno
  if grep -q $rollno $filename  #checking of rollno already exists
  then
    echo Record Already Exists
    echo "================================"
  else
    read -p "Name      : " name
    read -p "Class     : " class
    read -p "Attendance: " attendance
    echo -e "$rollno \t $name \t $class \t $attendance" >> $filename
    echo "================================"
  fi
}

update() {

  read -p "Roll no: " rollno
  val=($(grep -i $rollno $filename)) #array variable to store the line
  if grep -q $rollno $filename  #checking if pattern exists: pattern=rollno
  then
    echo Record Found:
    echo ${val[*]}
    read -p "New Attendance: " val[3] #3rd location contains attendance, editing the attendance
    sed -in "/$rollno/d" $filename #deleting the line
    echo ${val[*]} >> $filename #appending the updated attendance
    cat $filename
  else
    echo Record Not Found!
  fi
}

delete() {

  read -p "Roll no: " rollno
  val=($(grep -i $rollno $filename)) #array variable to store the line
  if grep -q $rollno $filename #checking if pattern exists: pattern=rollno
  then
    echo Deleting Record:
    echo ${val[*]}
    sed -in "/$rollno/d" $filename #deleting the line
    cat $filename
  else
    echo Record Not Found!
  fi
}

echo
echo Select Correct Option:
echo
echo 1. Create a new Database
echo 2. Add a new Attendance Record
echo 3. Update an Attendance
echo 4. Delete an Attendance Record
echo 5. Display Attendance Record
echo 6. Exit
echo ================================
read -p "Enter Choice: " ch
echo ================================

while [ $ch -ne 6 ]
do
  case $ch in
    1 )
      create
      ;;
    2 )
      insert
      ;;
    3 )
      update
      ;;
    4 )
      delete
      ;;
    5 )
      cat $filename
      ;;
    * )
      echo Wrong Choice! Select Correct Option
      ;;
  esac

  echo
  echo Select Correct Option
  echo
  echo 1. Create a new Database
  echo 2. Add a new Attendance Record
  echo 3. Update an Attendance
  echo 4. Delete an Attendance Record
  echo 5. Display Attendance Record
  echo 6. Exit
  echo ================================
  read -p "Enter Choice: " ch
  echo ================================
done
