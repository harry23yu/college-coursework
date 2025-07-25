/*Name: Harry Yu
Date: 5/14/23
Course number: CS 290*/

//window.addEventListener("DOMContentLoaded", domLoaded);

//Global variables
var numClicks = 0;
var totalClicks = 0;
var firstNumber = 0;
var secondNumber = 0;
var total = 0;
var mathSymbol = "+";
var goalNum = 0;

//The domLoaded function loads the game and adds the click functionality to the number
//and operator buttons.
function domLoaded() {
	const newButton = document.getElementById("newGame");
	newButton.addEventListener("click", newGame);
	const buttons = getGameBoardButtons();
	const operatorButtons = getOperatorButtons();
    generateNumbers();
	for (let button of buttons) {
		button.addEventListener("click", function () { clickFirstNumber(button); });
	}
	for (let operator of operatorButtons) {
		operator.addEventListener("click", function () { clickOperator(operator); });
	}
	newGame();
}

window.addEventListener("DOMContentLoaded", domLoaded);

// Returns the four buttons with the numbers.
function getGameBoardButtons() {
	return document.querySelectorAll("#gameBoardButtons > button");
}

//Returns the operator buttons.
function getOperatorButtons() {
	return document.querySelectorAll("#operatorButtons > button");
}

//The newGame function generates random numbers for the game board and a random 
//goal every time the new game button is clicked. It also clears the work area.
function newGame() {
	generateNumbers();
	goal();
	buttonReset();
	//winOrLoss();
	clearWorkArea();
	resetEverything();
}

//The goal function generates a random goal between -10 and 10.
function goal() {
	goalNum = document.getElementById("goalNum");
	let goalValueNum = -10 + Math.floor(Math.random() * 21);
	goalNum.innerHTML = goalValueNum;
}

//The generateNumbers function assigns four random numbers between 0 and 10 
//to each of the game board.
function generateNumbers() {
    let buttons = getGameBoardButtons();
    for (i = 0; i < buttons.length; i++) {
        let valueOfButton = Math.floor(Math.random() * 11);
        buttons[i].innerHTML = valueOfButton;
    }
}

//The resetEverything function resets the total number of clicks and the number 
//of clicks in the turn to 0. The message changes to the starting message.
function resetEverything() {
	totalClicks = 0;
	numClicks = 0;
	let message = document.getElementById("message");
	message.innerHTML = "Let's play! Click a number to start.";
}

//The winOrLoss function keeps track of how many wins and losses the player 
//has had before closing the tab or refreshing the page.
function winOrLoss() {
	let message = document.getElementById("message");
	let target = document.getElementById("goalNum");
	let winNumber = document.getElementById("numWins");
	let lossNumber = document.getElementById("numLosses");
	let targetNum = parseInt(target.innerHTML);
	let winNum = parseInt(winNumber.innerHTML);
	let lossNum = parseInt(lossNumber.innerHTML);
	if (totalClicks == 9 && total == targetNum) {
		message.innerHTML = "You won!";
		winNum++;
		winNumber.innerHTML = winNum;
	}
	if (totalClicks == 9 && total !== targetNum) {
		message.innerHTML = "You lost. Better luck next time!";
		lossNum++;
		lossNumber.innerHTML = lossNum;
	}
}

//The clearWorkArea function clears the work area after the new game button 
//is pressesd.
function clearWorkArea() {
	let eq1 = document.getElementById("eq1");
	let eq2 = document.getElementById("eq2");
	let eq3 = document.getElementById("eq3");
	eq1.innerHTML = "";
	eq2.innerHTML = "";
	eq3.innerHTML = "";
}

//The displayMessage function tells the player what to do, or if he or she 
//has won or lost the game.
function displayMessage() {
	let message = document.getElementById("message");
	if (totalClicks == 0 && numClicks == 0) {
		message.innerHTML = "Let's play! Click a number to start.";
	}
	if (totalClicks !== 0 && numClicks == 1) {
		message.innerHTML = "Click an operator.";
	}
	if (totalClicks !== 0 && (numClicks == 0 || numClicks == 2)) {
		message.innerHTML = "Click a number.";
	}
}

//The clickFirstNumber function keeps track of the number of clicks in the 
//current turn, and the total number of clicks in the game. It disables the 
//number buttons after a number has pressed, allowing the player to only click 
//the operator buttons. After an operator button is clicked, the number buttons 
//can be clicked by the player. This function also tracks which buttons have been 
//clicked, so that if a button has already been clicked, it is disabled.

//NOTE: The clickFirstNumber function works for both clicks, even if the player 
//is clicking the second number in an equation. I called this function 
//clickFirstNumber because I was originally intending to have another function 
//called clickSecondNumber, but then I decided that one function like this is 
//good enough. I didn't change the clickFirstNumber function to clickNumber because 
//then I would have to change clickFirstNumber to clickNumber everywhere else in 
//my code, and I didn't want to do that just in case I would mess up my code.

function clickFirstNumber(button) {
	let message = document.getElementById("message");
	//message.innerHTML = "Click a number";
	//let equations = document.getElementById("equation");
	let eq1 = document.getElementById("eq1");
	let eq2 = document.getElementById("eq2");
	let eq3 = document.getElementById("eq3");
	let numButtons = getGameBoardButtons();
	let operators = getOperatorButtons();
	for (let b of numButtons) {
		//equations.innerHTML = button.innerHTML;
		b.disabled = true; //After the first number is clicked, the player must choose an operator
	}
		//button.parentNode.removeChild(button);
	let value = button.innerHTML;
	console.log("Value is " + value); //testing line
	if (numClicks == 0) {
		firstNumber = value; //The first number is the value of the first button clicked
		//message.innerHTML = "Click a number";
		//displayMessage();
	}
	else {
		secondNumber = value; //The second number is the value of the second button clicked
	}
	button.className = "used"; //After clicking a button with a number, it is used and it has to be disabled
	numClicks++; //Number of clicks in the current turn
	totalClicks++; //Number of total clicks in the current game
	console.log("Num clicks: " + numClicks); //testing line
	console.log("Total clicks: " + totalClicks); //testing line
	displayMessage(); //Displays the appropriate message on the screen
	if (numClicks == 3) {
		if (mathSymbol == "+") {
			total = parseInt(firstNumber) + parseInt(secondNumber);
		}
		if (mathSymbol == "-") {
			total = parseInt(firstNumber) - parseInt(secondNumber);
		}
		if (mathSymbol == "*") {
			total = parseInt(firstNumber) * parseInt(secondNumber);
		}
		if (totalClicks == 3) { //First equation displayed in work area
			eq1.innerHTML = firstNumber + mathSymbol + secondNumber + " = " + total;
		}
		if (totalClicks == 6) { //Second equation displayed in work area
			eq2.innerHTML = firstNumber + mathSymbol + secondNumber + " = " + total;
		}
		if (totalClicks == 9) { //Third equation displayed in work area
			eq3.innerHTML = firstNumber + mathSymbol + secondNumber + " = " + total;
		}
		console.log("Current value is " + total); //testing line
		button.innerHTML = total; //The second button clicked should have the total value (ex: if 2 + 8 = 10, the second button should have a value of 10)
		button.disabled = false; //The second button that is clicked should not be disabled
		button.className = "";
		for (let b of numButtons) {
			//equations.innerHTML = button.innerHTML;
			if (button.className !== "used") {
				b.disabled = false; //If the button isn't used, then it should not be disabled
			}
		}
		numClicks = 0; //After every turn, reset the number of clicks in the current turn to 0
	}
	if (totalClicks == 9) { //After 9 total clicks (3 turns), the game ends
		winOrLoss(); //Checks to see if the player won or lost
		for (let b of numButtons) {
			b.disabled = true; //After the game is over, the buttons should be disabled
		}
	}
}

//The clickOperator function allows the player to click an operator after choosing 
//their first number.
function clickOperator(operator) {
	if (numClicks == 1) { //Only allows the player to click an operator after choosing the first number
		numClicks++;
		totalClicks++;
		let numButtons = getGameBoardButtons();
		let message = document.getElementById("message");
		//message.innerHTML = "Click an operator";
		displayMessage(); //Displays the appropriate message on the screen
		let operators = getOperatorButtons();
		//equations.innerHTML = operator.innerHTML;
		mathSymbol = operator.innerHTML; //Keeps track of whether the player clicked a +, -, or *
		console.log(mathSymbol); //testing line
		for (let button of numButtons) {
			//equations.innerHTML = button.innerHTML;
			button.disabled = false; //After clicking an operator, the number buttons should not be disabled
			//button.parentNode.removeChild(button);
			let value = button.innerHTML;
			if (button.className == "used") {
				button.disabled = true; //If a number button is used, it should be disabled
			}
		}
		console.log("Operator is " + mathSymbol); //testing line
	}
}

//The buttonReset function allows the number buttons to be clickable after clicking 
//the new game button.
function buttonReset() {
	let buttons = getGameBoardButtons();
	for (let button of buttons) {
		button.disabled = false;
		button.className= "";    
	}
}