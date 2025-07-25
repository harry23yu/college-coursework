/*Name: Harry Yu
Date: 5/7/2023
Course: CS 290*/

//This function creates the array of scores
function parseScores(scoresString) {
   // TODO: Compete the function
   let scoresArray = scoresString.split(" ");
   return scoresArray;
}

//This function returns how many As, Bs, Cs, Ds, and Fs are in the scores array.
//The number of As is the first number, number of Bs is the second number, etc.
function buildDistributionArray(scoresArray) {
   // TODO: Compete the function
   const distributionArray = [0, 0, 0, 0, 0];
   for (i = 0; i < scoresArray.length; i++) {
      if (scoresArray[i] >= 90) {
         distributionArray[0]++;
      }
      else if (scoresArray[i] >= 80) {
         distributionArray[1]++;
      }
      else if (scoresArray[i] >= 70) {
         distributionArray[2]++;
      }
      else if (scoresArray[i] >= 60) {
         distributionArray[3]++;
      }
      else {
         distributionArray[4]++;
      }
   }
   return distributionArray;
}

//This function creates a graph of how many times each grade occurs
function setTableContent(userInput) {
   // TODO: Compete the function
   let gradeTable = document.getElementById("distributionTable");
   let parsedScores = parseScores(userInput);
   let gradeDistributionArray = buildDistributionArray(parsedScores);
   let gradeCountArray = [];
   let graphHeightArray = [];
   let row1 = document.getElementById("firstRow");
   let row3 = document.getElementById("thirdRow");
   for (i = 0; i < 5; i++) {
      gradeCountArray[i] = row3.insertCell(i);
      gradeCountArray[i].innerHTML = gradeDistributionArray[i];
      graphHeightArray[i] = row1.insertCell(i);
      let barHeight = (gradeDistributionArray[i] * 10) + "px";
      let barNum = "bar" + i;
      console.log(barHeight); //Testing statement
      console.log(barNum); //Testing statement
      graphHeightArray[i].innerHTML = "<div style = 'height'" + barHeight + "class = " + barNum + "></div>";
   }  
}

// The argument can be changed for testing purposes
setTableContent("45 78 98 83 86 99 90 59");