<!DOCTYPE html>
<html>
<head>
  <title>Car Loan Page</title>
  <link rel="stylesheet" href="css/style.css">
</head>

<body style="background-color: #D8D8D8; ">

  <h1>Manokamana Finances</h1>
  <h4>Fulfil your wishes...</h4>

  <div class="topnav">
    <a href="Homepage.php">Home</a>
    <div class="dropdown">
      <button class="dropbtn">Loans</button>
      <div class="dropdown-content">
        <a href="PersonalLoanpage.php">Personal Loan</a>
        <a href="SeniorCitizenLoanpage.php">Senior Citizen Loan</a>
        <a href="GoldLoanpage.php">Gold Loan</a>
        <a href="HousingLoanpage.php">Housing Loan</a>
        <a href="StudentLoanpage.php">Student Loan</a>
        <a class="active" href="CarLoanpage.php">Car Loan</a>
      </div>
    </div>
    <a href="ContactUspage.php">Contact Us</a>
    <a href="Tutorialpage.php">Tutorial</a>
  </div>

  <div class="container">

    <img src="images/Car Loan.jpg" width="100%" height="700">
    <div class="content">

      <div class="formstyle">
        <?php include('test_form.php')?>

        <h2 style="text-align: center; margin-bottom: -5px; margin-top: -5px">Application Form</h2>
        <p><span style="color: red">* required field.</span></p>

        <form method = "post" action = "<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
          <label for="fname">First Name:</label><br />
          <input type="text" name="fname" placeholder="Your first name..">
          <span style="color: red"><?php echo $fnameErr;?></span><br />

          <label for="lname">Last Name:</label><br />
          <input type="text" name="lname" placeholder="Your last name..">
          <span style="color: red"><?php echo $lnameErr;?></span><br />

          <label for="email">Email ID:</label><br />
          <input type="text" name="email" placeholder="Your email id..">
          <span style="color: red"><?php echo $emailErr;?></span><br />

          <label for="phno">Mobile No:</label><br />
          <input type="text" name="phno" placeholder="Your mobile no..">
          <span style="color: red"><?php echo $phnoErr;?></span><br />

          <label for="pincode">Enter Pin Code:</label><br>
          <input type="text" name="pincode" placeholder="Your zipcode..">
          <span style="color: red"><?php echo $pinErr;?></span><br />

          <label for="occupation">Occupation:</label><br>
          <select name="occupation">
            <option value=0>Select Occupation..</option>
            <option value=1>Self-Employed</option>
            <option value=2>Employed</option>
            <option value=3>Buisness</option>
            <option value=4>Student</option>
            <option value=5>Other</option>
          </select>
          <span style="color: red"><?php echo $occErr;?></span><br />

          <label for="income">Income:</label><br>
          <input type="text" name="income" placeholder="Your income..">
          <span style="color: red"><?php echo $incErr;?></span><br />

          <input type="submit" value="Apply Now">
          <input type="reset" value="Reset">
        </form>
      </div>

      <div style="float: left; font-size: 16pt;  text-align: left; width: 50%; ">
        <br><b>What is a Car Loan?</b><br><br>
        What if a car is the right size, has all the right features, and gives the right mileage but the funds are not enough? That is what car finance is for. A car loan is a loan taken to fund the purchase of a car.
      </div>

      <div style="float: left; font-size: 16pt;  text-align: left; width: 50%; ">
        <b>Why Should You Take a a Car Loan?</b><br><br>
        Taking a car loan works in your favour as you get to bring home your dream drive fast. Moreover, the loan amount + interest can be paid off in easy monthly installments. Here's how: <br>
        <ul>
          <li>High loan principal</li>
          <li>Competitive interest rates</li>
          <li>Flexibility</li>
          <li>Quick processing and minimal paperwork</li>
        </ul>
      </div>
    </div>
  </div>
</body>
</html>