// Your solution goes here
function playGuessingGame(numToGuess, totalGuesses = 10) {
    let numOfGuesses = 0;
    while (numOfGuesses < totalGuesses) {
        numJustGuessed = prompt(numOfGuesses === 0 ? "Enter a number between 1 and 100." : /*If this is the first guess*/
        (numJustGuessed < numToGuess ? `${numJustGuessed} is too small. Guess a larger number.` : `${numJustGuessed} is too large. Guess a smaller number.`)); /*If this is not the first guess*/

        if (numJustGuessed === null) {
            return 0;
        }
        numJustGuessed = Number(numJustGuessed);
        if (isNaN(numJustGuessed)) {
            alert("Please enter a number.");
            continue;
        }
        numOfGuesses++;
        if (numJustGuessed === numToGuess) {
            return numOfGuesses;
        }
    }
    return 0;
}
  