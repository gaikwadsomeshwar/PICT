<?php
// define variables and set to empty values
$fnameErr = $lnameErr = $emailErr = $phnoErr = $pinErr = $occErr = $incErr = "";
$fname = $lname = $email = $phno = $pincode = $occupation = $income = "";

if($_SERVER["REQUEST_METHOD"] == "POST") {
  if (empty($_POST["fname"])) {
    $fnameErr = "First Name is required";
  }
  else {
    $fname = test_input($_POST["fname"]);
    if (!preg_match("/^[a-zA-Z-' ]*$/",$fname)) {
      $fnameErr = "Only letters and white space allowed";
    }
  }

  if(empty($_POST["lname"])) {
    $lnameErr = "Last Name is required";
  }
  else {
    $lname = test_input($_POST["lname"]);
    if (!preg_match("/^[a-zA-Z-' ]*$/",$lname)) {
      $lnameErr = "Only letters and white space allowed";
    }
  }

  if(empty($_POST["email"])) {
    $emailErr = "Email is required";
  }
  else {
    $email = test_input($_POST["email"]);

    // check if e-mail address is well-formed
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
      $emailErr = "Invalid Email format";
    }
  }

  if(empty($_POST["phno"])) {
    $phnoErr = "Phone Number is required";
  }
  else {
    $phno = test_input($_POST["phno"]);
    if(!(preg_match('/^\+[0-9]{1,2}-[7-9]{2}[0-9]{8}$/',$phno))) {
      $phnoErr = "Invalid Mobile Number";
    }
  }

  if(empty($_POST["pincode"])) {
    $pinErr = "Zipcode is required";
  }
  else {
    $pincode = test_input($_POST["pincode"]);

    if(!(is_numeric($pincode) && strlen($pincode)==6)) {
      $pinErr = "Invalid Zipcode";
    }
  }

  if($_POST["occupation"]==0) {
    $occErr = "Occupation is required";
  }
}

if(empty($_POST["income"])) {
  $incErr = "Income is required";
}
else {
  $income = test_input($_POST["income"]);

  if(!(is_numeric($income))) {
    $incErr = "Invalid Income";
  }
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>
