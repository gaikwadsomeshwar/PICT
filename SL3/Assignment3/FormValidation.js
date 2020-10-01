function validateForm() {

   var fname=document.getElementById("fname");
   var lname=document.getElementById("lname");
   var email=document.getElementById("email");
   var phno=document.getElementById("mobileno");
   var pincode=document.getElementById("pincode");
   var income=document.getElementById("income");

   if(fname.value.trim()=="") {
     alert("Enter your First Name");
     return false;
   }
   if(lname.value.trim()=="") {
     alert("Enter your Last Name");
     return false;
   }
   if(email.value.trim()=="") {
     alert("Enter your Email ID");
     return false;
   }
   if(phno.value.trim()=="") {
     alert("Enter a Phone Number");
     return false;
   }
   if(pincode.value.trim()=="") {
     alert("Enter a Pincode");
     return false;
   }
   if(income.value.trim()=="") {
     alert("Enter an Income");
     return false;
   }
   return true;
}
