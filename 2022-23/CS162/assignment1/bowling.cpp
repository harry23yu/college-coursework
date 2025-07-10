/******************************************************
** Program: bowling.cpp
** Author: Harry Yu
** Date: 10/9/2022
** Description: This program simulates a game of bowling
 * with random numbers. Every time the user press enter, a
 * random number of pins will be knocked down each roll.
** Input: When the user press enter, each roll will knock
 * down between 0 to 10 pins. If a strike is achieved in the first 
 * roll, the user will go on to the next frame. If a strike isn't
 * achieved in the first roll, then the second roll in the each
 * frame allows the user to knock down between 0 and the remaining
 * pins. Each roll is randomly generated, not by user input.
** Output: After each roll, frame scores and the total score
 * is displayed.
******************************************************/

/*****************************************************
 * The print_array and main functions have more than 15 lines because there
 * are so many different roll combinations. For frames 1-9, the player
 * can bowl a strike, an open frame, a spare without a gutter ball, and
 * a spare with a gutter ball (- /). For frame 10, there are 7 different
 * combinations: 
 * 
 * Open frame, no 3rd roll (ex: 3 and 4)
 * 3rd roll, with strike on 1st roll and no more strikes/spares (ex: X 3 4)
 * 3rd roll, with strike on 1st roll and then a spare (X 3 /)
 * 3rd roll, with spare on 2nd roll and strike on 3rd roll (ex: 4 / X)
 * 3rd roll, with spare on 2nd roll and no more strikes (ex: 4 / 5)
 * 3rd roll, with strike on first 2 rolls and no more strikes (ex: X X 3)
 * 3rd roll, with strike on all 3 rolls (ex: X X X)
 * 
 * Every combination needs to display correctly in the scoresheet. In addition,
 * the total score and the other arrays need to be calculated and printed
 * correctly for all combinations. This is why more than 15 lines are required
 * to write the print_array and main functions.
******************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*********************************************************************
** Function: press_enter()
** Description: Press enter to roll the ball and knock down pins.
** Parameters: None
** Pre-Conditions: Before rolling the ball, the previous scoresheet and 
* total score are displayed.
** Post-Conditions: After rolling the ball, the updated scoresheet and 
* total score are displayed.
*********************************************************************/
void press_enter() {
    string temp;
    cout << "Press enter to roll the ball...";
	getline(cin, temp);
}

/*********************************************************************
** Function: print_array(int array[], int size)
** Description: After each roll, it prints the scoresheet with the roll
* info (spare, strike, gutterball, or number of pins knocked down)
** Parameters: array[], size
** Pre-Conditions: The size of the array must be 21, because that is the
* number of maximum possible rolls in a bowling game. The number of pins
* knocked down also must be an integer between 0 and 10.
** Post-Conditions: If the first roll is a strike, then the player will
* move on to the next frame. If the first roll is NOT a strike, then the
* player will have a second roll to knock down between 0 pins and the
* remaining pins left.
*********************************************************************/
void print_array(int array[], int size) {
    cout << "   1        2        3        4        5        6        7        8        9        10" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        if (array[i] == -1) {
            cout << " "; //if element is -1 (if there is no roll), print nothing
        }
        else {
            if ((array[i] + array[i-1]) == 10 && (i % 2 == 1)) {
                cout << " / "; //if rolled a spare, print "/"
            }
            else if (array[i] == 0) {
                cout << " - "; //if rolled a gutter ball, print "-"
            }
            else if (array[19] + array[20] == 10 && (i == 20)) {
                cout << " / "; //if rolled a spare during the final two rolls, print "/"
                break;
                if (array[20] >= 1 && array[20] <= 9) {
                    cout << " " << array[i] << " "; //print number of pins knocked down for final roll if it's between 1-9
                    break;
                }
            }
            else if (array[i] >= 1 && array[i] <= 9) {
                cout << " " << array[i] << " "; //if rolled 1-9 and no spare, print the value of the roll (# pins knocked down)
            }
            else if (array[i] == 10) {
                cout << " X   "; //if rolled a strike, print "X"
            }
        }
        if ((i % 2 == 1) && i <= 17) {
            cout << " | "; //after each frame, print a vertical line (except after the 10th frame)
        }
    }
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
}

/*********************************************************************
** Function: print_score(int array[], int size)
** Description: After each roll, a total score will be caulculated.
** Parameters: array[], size
** Pre-Conditions: The size of the array must be 21, because the total
* score will be based on each roll, and there are a maximum of 21 rolls.
* The total score must be 0 or greater, and it must be an integer.
** Post-Conditions: The total score must be based on all previous rolls
* by the player, and take account into any strikes and spares scored.
*********************************************************************/
void print_score(int array[], int size) {
    int totalScore = 0;
    for (int i = 0; i < size; i++) {
        totalScore = totalScore + array[i];
    }
}

/*********************************************************************
** Function: print_frameScore(int array[], int size)
** Description: After each roll, frame scores will be printed.
** Parameters: array[], size
** Pre-Conditions: The size of the array must be 10, because there are 10
* frames. Frame scores must be 0 or greater, and it must be an integer.
** Post-Conditions: Total scores after each frame should be printed out.
* Scores that have been printed for completed frames do not change for
* the whole game.
*********************************************************************/ 
void print_frameScore(int array[], int size) {
    int totalScore = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == -1) {
            cout << " "; //if element is -1 (if there is no roll), print nothing
        }
        else {
            if (i == 0) {
                cout << "  "; //the 1st frame is at the edge of the "screen," which means the space is smaller
            }
            if (i >= 1) {
                cout << "       "; 
            }
            cout << totalScore + array[i];
        }
    }
}

/*********************************************************************
** Function: greeting()
** Description: Asks the player for their name and welcomes them.
** Parameters: None
** Pre-Conditions: The user can print any name they want (numbers
* included, but no spaces).
** Post-Conditions: When the user presses enter after finishing typing
* their name, a welcome message must be printed and the game will start.
*********************************************************************/
void greeting() {
    string player;
    cout << "What is your name? ";
    cin >> player;
    cout << "Welcome to bowling, " << player << "!" << endl;
    cout << " " << endl;
}

/*********************************************************************
** Function: main()
** Description: Simulates a game of bowling.
** Parameters: None
** Pre-Conditions: All rolls are random. For the first roll in a frames 1-9,
* the player will knock down between 0 and 10 pins. If it's a strike, the
* player moves onto the next roll without a second roll in the frame. If
* it's not a strike, the player will have a second chance at knocking
* down the remaning pins. For frame 10, the player will get a third roll if
* and only if at least one strike or spare is achieved on the next two rolls.
** Post-Conditions: After each roll, the scoresheet and the total score
* must be printed. When all of the rolls have been finished, the player will
* be asked if they want to play again.
*********************************************************************/
int main() {
    //Set a random number generator
    srand(time(NULL));
    
    //Greets the player
    greeting();
    
    //Create a pins and score array (size 21 for up to 21 rolls), and score after each frame array (size 10 for 10 frames)
    int pins[21];
    int score[21];
    int totalScoreAfterFrame[10];
    
    //Initialize all 3 arrays
    for (int i = 0; i < 21; i++) {
        pins[i] = -1;
    }
    for (int i = 0; i < 21; i++) {
        score[i] = -1;
    }
    for (int i = 0; i < 10; i++) {
        totalScoreAfterFrame[i] = -1;
    }
    
    //First 9 frames (max 2 rolls per frame)
    int totalScore = 0;
    for (int i = 0; i < 9; i++) {
        //1st roll (let the user press enter to roll)
        press_enter();
        int roll1 = rand() % 11; //must be between 0 and 10 pins
        if (roll1 == 0) {
            cout << "Oh no! You rolled a gutter ball. Try harder next time!" << endl;
        }
        if (roll1 >= 1 && roll1 <= 9) {
            cout << "You knocked down " << roll1 << " pins." << endl;
            totalScore = totalScore + roll1;
        }
        if (roll1 == 10) {
            cout << "Amazing! You got a strike. Great job!" << endl;
            totalScore = totalScore + roll1;
            totalScoreAfterFrame[i] = totalScore;
        }
        if ((pins[(i*2)-2] + pins[(i*2)-1] == 10)) {
            totalScore = totalScore + roll1; //calculate spare score
        }
        if (((pins[(i*2)-4] == 10) && (pins[(i*2)-2] == 10)) && ((pins[(i*2)-3] == -1) && (pins[(i*2)-1] == -1))) {
            totalScore = totalScore + 20; //calculate strike score if every roll was a strike
        }
        
        //Modify all 3 arrays after 1st roll
        pins[i*2] = roll1;
        score[i*2] = roll1;
        totalScoreAfterFrame[i] = totalScore;
        
        //Print all 3 arrays and total score after 1st roll
		print_array(pins, 21);
		print_score(score, 21);
		print_frameScore(totalScoreAfterFrame, 10);
		cout << " " << endl;
		cout << "Your total score is " << totalScore << endl;
		
		//2nd roll (only if 1st roll is not a strike)
		if (roll1 != 10) {
		    press_enter();
		    int roll2 = rand() % (11-roll1); //2nd roll must be between 0 and (10-roll1)
		    if (roll2 == 0) {
		        cout << "Oh no! You rolled a gutter ball. Try harder next time!" << endl;
		    }
		    if (roll2 != 0 && roll2 != (10-roll1)) {
		        cout << "You knocked down " << roll2 << " pins." << endl;
		        totalScore = totalScore + roll2;
		    }
		    if (roll2 == (10-roll1)) {
		        cout << "Well done. You got a spare." << endl;
		        totalScore = totalScore + roll2;
		    }
		    if (((pins[(i*2)-2]) == 10) && (pins[(i*2)-1] == -1)) {
                totalScore = totalScore + roll1 + roll2; // calculate strike score
            }
            
		    //Modify all 3 arrays after 2nd roll
		    pins[i*2+1] = roll2;
		    score[i*2+1] = roll2;
		    totalScoreAfterFrame[i] = totalScore;
		    
		    //Print all 3 arrays and total score after 2nd roll
		    print_array(pins, 21);
		    print_score(score, 21);
		    print_frameScore(totalScoreAfterFrame, 10);
		    cout << " " << endl;
		    cout << "Your total score is " << totalScore << endl;
		}
    }
    
    //10th frame (i=18 for 19th roll)
    for (int i = 18; i < 21; i++) {
        //1st roll
        press_enter();
        int roll1 = rand() % 11; //1st roll must be between 0 and 10 pins
        if (roll1 == 0) {
            cout << "Oh no! You rolled a gutter ball. Try harder next time!" << endl;
        }
        if (roll1 >= 1 && roll1 <= 9) {
            cout << "You knocked down " << roll1 << " pins." << endl;
            totalScore = totalScore + roll1;
        }
        if (roll1 == 10) {
            cout << "Amazing! You got a strike. Great job!" << endl;
            totalScore = totalScore + roll1;
        }
        //Modify the pins and score array after 1st roll (10th frame)
        pins[i] = roll1;
        score[i] = roll1;
        
        //Print all 3 arrays and total score after 1st roll (10th frame)
		print_array(pins, 21);
		print_score(score, 21);
		print_frameScore(totalScoreAfterFrame, 10);
		cout << " " << endl;
		cout << "Your total score is " << totalScore << endl;
        
        //2nd roll (if 1st roll was NOT a strike)
		if (roll1 != 10) {
		    press_enter();
		    int roll2 = rand() % (11-roll1); //2nd roll must be between 0 and (10-roll1)
		    if (roll2 == 0) {
		        cout << "Oh no! You rolled a gutter ball. Try harder next time!" << endl;
		    }
		    if (roll2 != 0 && roll2 != (10-roll1)) {
		        cout << "You knocked down " << roll2 << " pins." << endl;
		        totalScore = totalScore + roll2;
		    }
		    if (roll2 == (10-roll1)) {
		        cout << "Well done. You got a spare." << endl;
		        totalScore = totalScore + roll2;
		    }
		    //Modify all 3 arrays after 2nd roll (10th frame)
		    pins[i+1] = roll2;
		    score[i+1] = roll2;
		    totalScoreAfterFrame[9] = totalScore;
		    
		    //Print all 3 arrays and total score after 2nd roll (10th frame)
		    print_array(pins, 21);
		    print_score(score, 21);
		    print_frameScore(totalScoreAfterFrame, 10);
		    cout << " " << endl;
		    cout << "Your total score is " << totalScore << endl;
		}
		
		//2nd roll (if first roll is a strike)
		if (roll1 == 10) {
		    press_enter();
		    int roll2 = rand() % 11; //2nd roll must be between 0 and 10
		    if (roll2 == 0) {
		        cout << "Oh no! You rolled a gutter ball. Try harder next time!" << endl;
		    }
		    if (roll2 >= 1 && roll2 <= 9) {
		        cout << "You knocked down " << roll2 << " pins." << endl;
		        totalScore = totalScore + roll2;
		    }
		    if (roll2 == 10) {
		        cout << "Amazing! You got a strike. Great job!" << endl;
		        totalScore = totalScore + roll2;
		    }
		    //Modify the pins and score array after 2nd roll
		    pins[i+1] = roll2;
		    score[i+1] = roll2;
		    
		    //Print all 3 arrays and total score after 2nd roll
		    print_array(pins, 21);
		    print_score(score, 21);
		    print_frameScore(totalScoreAfterFrame, 10);
		    cout << " " << endl;
		    cout << "Your total score is " << totalScore << endl;
		}
		
		//3rd roll (only if at least one strike or spare is achieved after 2 rolls, that is, (pins[18] + pins[19]) >= 10)
		int roll3 = rand() % 11;
        if ((pins[i] + pins[i+1]) >= 10) {
            press_enter();
            //if only 1st roll is a strike
            if (pins[i] == 10 && pins[i+1] != 10) {
                roll3 = rand() % (11-pins[i+1]); //3rd roll must be between 0 and (10-roll2)
                if (roll3 == (10-pins[i+1])) {
                    //Modify all 3 arrays after the 3rd roll
                    pins[20] = roll3;
                    score[20] = roll3;
                    totalScore = totalScore + roll3;
                    totalScoreAfterFrame[9] = totalScore;
                    cout << "Well done. You got a spare." << endl;
                    
                    //Print all 3 arrays and total score after 3rd roll
                    print_array(pins, 21);
                    print_score(score, 21);
                    print_frameScore(totalScoreAfterFrame, 10);
                    cout << " " << endl;
                    cout << "Your total score is " << totalScore << endl;
                    
                    //Ask if user wants to play again
                    string playAgain;
                    cout << "Do you want to play again? If yes, type 'yes.' ";
                    cin >> playAgain;
                    cout << " " << endl;
                    while (playAgain == "yes") {
                        main();
                    }
    		        return 0;
                }
            }
            //if both 1st and 2nd rolls are strikes
            if (pins[i] == 10 && pins[i+1] == 10) {
                roll3 = rand() % 11; //3rd roll must be between 0 and 10 pins
                //Modify pins and score array after 3rd roll
                pins[20] = roll3;
                score[20] = roll3;
                if (roll3 == 10) {
                    cout << "Amazing! You got a strike. Great job!" << endl;
                    totalScore = totalScore + roll3;
                    
                    //Print all 3 arrays and total score after 3rd roll
                    print_array(pins, 21);
                    print_score(score, 21);
                    totalScoreAfterFrame[9] = totalScore; //modify frame score array after 3rd roll
                    print_frameScore(totalScoreAfterFrame, 10);
                    cout << " " << endl;
                    cout << "Your total score is " << totalScore << endl;
                    
                    //Ask if user wants to play again
                    string playAgain;
                    cout << "Do you want to play again? If yes, type 'yes.' ";
                    cin >> playAgain;
                    cout << " " << endl;
                    while (playAgain == "yes") {
                        main();
                    }
    		        return 0;
                }
            }
            if (roll3 == 0) {
                cout << "Oh no! You rolled a gutter ball. Try harder next time!" << endl;
            }
            else if (roll3 >= 1 && roll3 <= 9) {
                cout << "You knocked down " << roll3 << " pins." << endl;
                totalScore = totalScore + roll3;
            }
            else if (roll3 == 10) {
                cout << "Amazing! You got a strike. Great job!" << endl;
                totalScore = totalScore + roll3;
            }
            //Modify all 3 arrays after 3rd roll, regardless of the outcome of the first 2 rolls
            pins[i+2] = roll3;
            score[i+2] = roll3;
            totalScoreAfterFrame[9] = totalScore;
            
            //Print all 3 arrays and total score after 3rd roll, regardless of the outcome of the first 2 rolls
    		print_array(pins, 21);
    		print_score(score, 21);
    		print_frameScore(totalScoreAfterFrame, 10);
		    cout << " " << endl;
    		cout << "Your total score is " << totalScore << endl;
    		
    		//Ask if user wants to play again
    		string playAgain;
            cout << "Do you want to play again? If yes, type 'yes.' ";
            cin >> playAgain;
            cout << " " << endl;
            while (playAgain == "yes") {
                main();
            }
    		return 0;
        }
        
        //Ask if user wants to play again if there were only 2 rolls in the 10th frame
        else {
            string playAgain;
            cout << "Do you want to play again? If yes, type 'yes.' ";
            cin >> playAgain;
            cout << " " << endl;
            while (playAgain == "yes") {
                main();
            }
            return 0;
        }
    }
}