/*Name: Harry Yu
Date: 5/7/2023
Class: CS 290*/

let playerTurn = true;
let computerMoveTimeout = 0;

const gameStatus = {
	MORE_MOVES_LEFT: 1,
	HUMAN_WINS: 2,
	COMPUTER_WINS: 3,
	DRAW_GAME: 4
};

window.addEventListener("DOMContentLoaded", domLoaded);

//This function is called when the game starts after the DOM loads
function domLoaded() {
	// Setup the click event for the "New game" button
	const newBtn = document.getElementById("newGameButton");
	newBtn.addEventListener("click", newGame);

	// Create click-event handlers for each game board button
	const buttons = getGameBoardButtons();
	for (let button of buttons) {
		button.addEventListener("click", function () { boardButtonClicked(button); });
	}

	// Clear the board
	newGame();
}

// Returns an array of 9 <button> elements that make up the game board. The first 3 
// elements are the top row, the next 3 the middle row, and the last 3 the 
// bottom row. 
function getGameBoardButtons() {
	return document.querySelectorAll("#gameBoard > button");
}

//This function checks to see if the player or the computer has won the game of Tic-Tac-Toe
function checkForWinner() {
	
	const buttons = getGameBoardButtons();

	// Ways to win
	const possibilities = [
		[0, 1, 2], [3, 4, 5], [6, 7, 8], // rows
		[0, 3, 6], [1, 4, 7], [2, 5, 8], // columns
		[0, 4, 8], [2, 4, 6] // diagonals
	];

	// Check for a winner first
	for (let indices of possibilities) {
		if (buttons[indices[0]].innerHTML !== "" &&
			buttons[indices[0]].innerHTML === buttons[indices[1]].innerHTML &&
			buttons[indices[1]].innerHTML === buttons[indices[2]].innerHTML) {
			
			// Found a winner
			if (buttons[indices[0]].innerHTML === "X") {
				return gameStatus.HUMAN_WINS;
			}
			else {
				return gameStatus.COMPUTER_WINS;
			}
		}
	}

	// See if any more moves are left
	let foundEmpty = false;
	for (let button of buttons) {
		if (button.innerHTML !== "X" && button.innerHTML !== "O") {
			return gameStatus.MORE_MOVES_LEFT;
		}
	}

	// If no winner and no moves left, then it's a draw
	return gameStatus.DRAW_GAME;
}

//This function creates a new game of Tic-Tac-Toe
function newGame() {
	// TODO: Complete the function
	clearTimeout(computerMoveTimeout);
	computerMoveTimeout = 0;
	const gameButtons = getGameBoardButtons();
	for (let i = 0; i < gameButtons.length; i++) {
		gameButtons[i].innerHTML = "";
		gameButtons[i].className = "";
		gameButtons[i].removeAttribute("disabled");
	}
	playerTurn = true;
	let turnText = document.getElementById("turnInfo");
	turnText.innerHTML = "Your turn";
}

//This function allows the player to put an X when its their turn
function boardButtonClicked(button) {
	// TODO: Complete the function
	if (playerTurn == true) {
		button.innerHTML = "X";
		button.classList.add("x");
		button.disabled = true;
		switchTurn();
	}
}

//This function switches the turn between the player and the computer and checks to see if someone has won the game, or if it is a draw
function switchTurn() {
	// TODO: Complete the function
	let gameStatus = checkForWinner();
	let turnText = document.getElementById("turnInfo");
	if (gameStatus == 1) {
		if (playerTurn == true) {
			computerMoveTimeout = setTimeout(makeComputerMove, 1000);
			//turnText.innerHTML = "Your turn";
		}
		if (playerTurn == false) {
			clearTimeout(computerMoveTimeout);
			computerMoveTimeout = 0;
			//turnText.innerHTML = "Computer's turn";
		}
		playerTurn = !playerTurn;
		if (playerTurn == true) {
			turnText.innerHTML = "Your turn";
		}
		if (playerTurn == false) {
			turnText.innerHTML = "Computer's turn";
		}
	}
	if (gameStatus >=2 && gameStatus <=4) {
		playerTurn = false;
		if (gameStatus == 2) {
			turnText.innerHTML = "You win!";
		}
		if (gameStatus == 3) {
			turnText.innerHTML = "Computer wins!";
		}
		if (gameStatus == 4) {
			turnText.innerHTML = "Draw game";
		}
	}
}

//This function allows the computer to place an O on an empty space when it's their turn
function makeComputerMove() {
	// TODO: Complete the function
	let availableButtons = getGameBoardButtons();
	let computerButton = availableButtons[Math.floor(Math.random() * availableButtons.length)];
	computerButton.innerHTML = "O";
	computerButton.classList.add("o");
	computerButton.disabled = true;
	switchTurn();
}