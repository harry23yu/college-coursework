/*Name: Harry Yu
Date: 5/21/23
Course number: CS 290*/

//This function checks to see if there are any errors with the name, email, and password.
function checkForm() {
   // TODO: Perform input validation
   var formValidationErrors = false;
   var validEmailTest = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,5}$/;
   var lowercaseTest = /[a-z]/;
   var uppercaseTest = /[A-Z]/;
   var digitTest = /[0-9]/;

   //Declare variables by getting the ID of the HTML elements so the computer knows where to 
   //check to see if a value is valid.
   var name = document.getElementById("fullName");
   var email = document.getElementById("email");
   var password = document.getElementById("password");
   var passwordConfirm = document.getElementById("passwordConfirm");
   var errorMessages = document.getElementById("formErrors");

   //The computer needs to know what is inside the input boxes.
   var nameValue = name.value;
   var emailValue = email.value;
   var passwordValue = password.value;
   var passwordConfirmValue = passwordConfirm.value;

   //Initially, hide the error messages and remove the errors. Only show the error messages 
   //if there are errors in the form.
   errorMessages.classList.add("hide");
   name.classList.remove("error");
   email.classList.remove("error");
   password.classList.remove("error");
   passwordConfirm.classList.remove("error");

   if (nameValue.length < 1) { //Make sure name contains at least one character.
      displayErrorMessage("Missing full name.");
      formValidationErrors = true;
      name.classList.add("error");
      console.log("Missing full name."); //Testing line
   }
   if (!validEmailTest.test(emailValue)) { //Make sure the email address is valid.
      displayErrorMessage("Invalid or missing email address.");
      formValidationErrors = true;
      email.classList.add("error");
      console.log("Invalid or missing email address."); //Testing line
   }
   if (passwordValue.length < 10 || passwordValue.length > 20) { //Make sure the password has the right length.
      displayErrorMessage("Password must be between 10 and 20 characters.");
      formValidationErrors = true;
      password.classList.add("error");
      console.log("Password must be between 10 and 20 characters."); //Testing line
   }
   if (!lowercaseTest.test(passwordValue)) { //Make sure the password contains at least one lowercase character.
      displayErrorMessage("Password must contain at least one lowercase character.");
      formValidationErrors = true;
      password.classList.add("error");
      console.log("Password must contain at least one lowercase character."); //Testing line
   }
   if (!uppercaseTest.test(passwordValue)) { //Make sure the password contains at least one uppercase character.
      displayErrorMessage("Password must contain at least one uppercase character.");
      formValidationErrors = true;
      password.classList.add("error");
      console.log("Password must contain at least one uppercase character."); //Testing line
   }
   if (!digitTest.test(passwordValue)) { //Make sure the password contains at least one digit.
      displayErrorMessage("Password must contain at least one digit.");
      formValidationErrors = true;
      password.classList.add("error");
      console.log("Password must contain at least one digit."); //Testing line
   }
   if (passwordValue !== passwordConfirmValue) { //Make sure the values inside the password and the password confirm boxes match.
      displayErrorMessage("Password and confirmation password don't match.");
      formValidationErrors = true;
      passwordConfirm.classList.add("error");
      console.log("Password and confirmation password don't match."); //Testing line
   }

   if (formValidationErrors == true) { //If there is at least one error within the form
      errorMessages.classList.remove("hide");
      console.log("There are errors.") //Testing line
   }
   if (formValidationErrors = false) { //If there are no errors within the form
      errorMessages.classList.add("hide");
      console.log("No errors.") //Testing line
   }
}

//This function helps display the error messages using an unordered list.
function displayErrorMessage(message) {
   var errorMessages = document.getElementById("formErrors");
   var messageList = document.createElement("ul");
   var errorMessage = document.createElement("li");
   errorMessage.innerHTML = message;
   messageList.appendChild(errorMessage);
   errorMessages.appendChild(messageList);
}

//This function allows the computer to check if there are any errors within the form after 
//the user clicks the submit button.
document.getElementById("submit").addEventListener("click", function(event) {
   checkForm();

   // Prevent default form action. DO NOT REMOVE THIS LINE
   event.preventDefault();
});