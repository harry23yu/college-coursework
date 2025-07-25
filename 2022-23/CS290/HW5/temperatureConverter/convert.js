/*Name: Harry Yu
Date: 5/7/2023
Class: CS 290*/

window.addEventListener("DOMContentLoaded", domLoaded);

/*This function detects if the celsius or fahrenheit values are valid numbers, 
and if they are, then the celsius will be converted into fahrenheit, and vice 
versa. An image will also appear based on the fahrenheit temperature.*/
function domLoaded() {
   // TODO: Complete the function
   let convertButton = document.getElementById("convertButton");
   let celsiusInput = document.getElementById("cInput");
   let fahrenheitInput = document.getElementById("fInput");
   let errorMessage = document.getElementById("errorMessage");
   const weatherImage = document.getElementById("weatherImage");

   convertButton.addEventListener("click", () => {
      let celsius = parseFloat(celsiusInput.value);
      let fahrenheit = parseFloat(fahrenheitInput.value);
      if (isNaN(celsiusInput.value)) {
         console.log("Celsius is not a number"); //Testing statement
         errorMessage.innerHTML = celsiusInput.value + " is not a number";
      }
      else if (isNaN(fahrenheitInput.value)) {
         console.log("Fahrenheit is not a number"); //Testing statement
         errorMessage.innerHTML = fahrenheitInput.value + " is not a number";
      }
      if (!isNaN(celsius)) {
         errorMessage.innerHTML = "";
         const convertedValue = (celsius * 9 / 5) + 32;
         fahrenheitInput.value = convertedValue;
      } 
      else if (!isNaN(fahrenheit)) {
         errorMessage.innerHTML = "";
         const convertedValue = (fahrenheit - 32) * 5/9;
         celsiusInput.value = convertedValue;
      }
      if (fahrenheitInput.value < 32) {
         weatherImage.src = "cold.png";
      }
      else if (fahrenheitInput.value >= 32 && fahrenheitInput.value <= 50) {
         weatherImage.src = "cool.png";
      }
      else {
         weatherImage.src = "warm.png";
      }
   });
  
   /*This function makes sure only one text field (celsius or 
   fahrenheit input) contains a value*/
   function clearValue() {
      if (this === celsiusInput && !isNaN(fahrenheitInput.value)) {
         fahrenheitInput.value = "";
      }
      if (this === fahrenheitInput && !isNaN(celsiusInput.value)) {
         celsiusInput.value = "";
      }
   }
   celsiusInput.addEventListener("input", clearValue);
   fahrenheitInput.addEventListener("input", clearValue);
}

/*This function converts C to F*/
function convertCtoF(degreesCelsius) {
   // TODO: Complete the function
   let degF = degreesCelsius * 9/5 + 32;
   return degF;
}

/*This function converts F to C*/
function convertFtoC(degreesFahrenheit) {
   // TODO: Complete the function
   let degC = (degreesFahrenheit - 32) * 5/9;
   return degC;
}
