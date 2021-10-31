#include<bits/stdc++.h>
using namespace std;

int blackCoins = 9;
int redCoin = 1;
int winner = 0;
int firstPlayerPoints = 0;
int secondPlayerPoints = 0;
int firstPlayerFoul = 0;
int secondPlayerFoul = 0;
int currentPlayer = 2;
int consecutiveNoStrikePlayer1 = 0;
int consecutiveNoStrikePlayer2 = 0;
bool switching = true;
int choiceIndex = 0;
vector<int> numbers;


/*
Print the menu for user
*/
void printList(){
    cout<<"1. Strike"<<endl;
    cout<<"2. Multistrike"<<endl;
    cout<<"3. Red strike"<<endl;
    cout<<"4. Striker strike"<<endl;
    cout<<"5. Defunct coin"<<endl;
    cout<<"6. None"<<endl;
}


/*
* When a player pcokets a coin
* Player wins a point
*/
void strike(){
    if(currentPlayer == 1){
        firstPlayerPoints++;
    }
    else if(currentPlayer == 2){
        secondPlayerPoints++;
    }
    blackCoins--;
}


/*
* when player pockets more than one coin
* Player wins 2 points
* 2 coins, that were pocketed, get back on to the carrom-board
*/
void multiStrike(){
    cout<<"Enter the number of coins pocketed: "<<endl;
    int coinsPocketed = numbers[choiceIndex];
    choiceIndex++;


    if(currentPlayer == 1){
        firstPlayerPoints += 2;
    }
    else if(currentPlayer == 2){
        secondPlayerPoints += 2;
    }

    //All, but two coins that were pocketed, get back on to the carrom board
    blackCoins = blackCoins - (coinsPocketed - 2);
}


/*
* When a player pockets red coin
* Player wins 3 points
* Other coins that were pocketed along with red coin would get back on to the carrom board
*/
void redStrike(){
    cout<<"Enter the number of coins pocketed apart from red coin: "<<endl;
    int extraCoinsPocketed = numbers[choiceIndex];
    choiceIndex++;


    if(currentPlayer == 1){
        firstPlayerPoints += 3;
    }
    else if(currentPlayer == 2){
        secondPlayerPoints += 3;
    }

    redCoin = 0;
}

/*
* When a player pockets the striker
* Player looses one point
*/
void strikerStrike(){
    if(currentPlayer == 1){
        firstPlayerPoints--;
        firstPlayerFoul++;
        consecutiveNoStrikePlayer1++;
    }
    else if(currentPlayer == 2){
        secondPlayerPoints --;
        secondPlayerFoul++;
        consecutiveNoStrikePlayer2++;
    }
}


/*
* When a coin is thrown out of the carrom-board due to strike
* Player loosed 2 points
* And the coin goes out of play
*/
void defunctCoin(){
    if(currentPlayer == 1){
        firstPlayerPoints -= 2;
        firstPlayerFoul++;
        consecutiveNoStrikePlayer1++;
        blackCoins--;
    }
    else if(currentPlayer == 2){
        secondPlayerPoints -= 2;
        secondPlayerFoul++;
        consecutiveNoStrikePlayer2++;
        blackCoins--;
    }
}

/*
* When a player does not pocket a coin
*/
void none(){
    if(currentPlayer == 1){
        consecutiveNoStrikePlayer1++;
    }
    else if(currentPlayer == 2){
        consecutiveNoStrikePlayer2++;
    }
}

/*
* Each player will have alternate turns
* If any player will try to strike a coin which is not present on the board, then he/she will get another turn
*/
void playerPlaying(int choice){

        cout<<"Player "<<currentPlayer<<": Choose an outcome from the list below"<<endl;
        printList();

        switch(choice){
            case 1: if(blackCoins>0){
                        strike();
                    }
                    else{
                        cout<<"No black coin left"<<endl;
                        switching = false;
                    }
                break;

            case 2: if(blackCoins>1){
                        multiStrike();
                    }
                    else{
                        cout<<"No black coin left"<<endl;
                        switching = false;
                    }
                break;

            case 3: if(redCoin == 1){
                        redStrike();
                    }
                    else{
                         cout<<"No red coin present"<<endl;
                         switching = false;
                     }
                break;

            case 4: strikerStrike();
                break;

            case 5: defunctCoin();
                break;

            case 6: none();
                break;

            default:  cout<<"Wrong input"<<endl;
                    switching = false;
                break;

        }

}


int tournament(vector<int> &numbers){
    bool playerWins = false;
    int winner;

    while(!playerWins){

        //switching players after each turn
        if(switching == true){
            if(currentPlayer == 1) currentPlayer = 2;
            else if(currentPlayer == 2) currentPlayer = 1;
        }
        else switching = true;

        for(; choiceIndex<numbers.size(); choiceIndex++){
            playerPlaying(numbers[choiceIndex]);

        }

        //CHECK ALL THE WINNING AND LOOSING CONDITIONS AFTER EACH STRIKE

        // When a player does not pocket a coin for 3 successive turns he/she loses a point
        if(currentPlayer == 1){
            if(consecutiveNoStrikePlayer1 == 3){
                 firstPlayerPoints--;
                 consecutiveNoStrikePlayer1 = 0;
             }
        }
        else if(currentPlayer == 2){
            if(consecutiveNoStrikePlayer2 == 3){
                 secondPlayerPoints--;
                 consecutiveNoStrikePlayer2 = 0;
             }
        }

        //When a player fouls 3 times, he/she loses an additional point

        if(currentPlayer == 1){
            if(firstPlayerFoul == 3){
                 firstPlayerPoints--;
                 firstPlayerFoul = 0;
             }
        }
        else if(currentPlayer == 2){
            if(secondPlayerFoul == 3){
                 secondPlayerPoints--;
                 secondPlayerFoul = 0;
             }
        }

        //winning condition 1
        if(currentPlayer == 1){
            if((firstPlayerPoints > 4) && (firstPlayerPoints - secondPlayerPoints > 2)){
                winner = currentPlayer;
                playerWins = true;
                break;
            }
        }
        else if(currentPlayer == 2){
            if((secondPlayerPoints > 4) && (secondPlayerPoints - firstPlayerPoints > 2)){
                winner = currentPlayer;
                playerWins = true;
                break;
            }
        }

        //when the coins are exhausted
        if(blackCoins == 0 && redCoin == 0){
            if(firstPlayerPoints > secondPlayerPoints){
                int leadingBy = firstPlayerPoints - secondPlayerPoints;
                if(leadingBy >= 3 && firstPlayerPoints>=5){
                    winner = currentPlayer;
                    playerWins = true;
                    break;
                }
                else{
                    winner = 0;
                    playerWins = true;
                    break;
                }
            }
            else if(secondPlayerPoints > firstPlayerPoints){
                int leadingBy = secondPlayerPoints - firstPlayerPoints;
                if(leadingBy >= 3 && secondPlayerPoints>=5){
                     winner = currentPlayer;
                     playerWins = true;
                     break;
                 }
                 else{
                     winner = 0;
                     playerWins = true;
                     break;
                 }
            }
        }
    }
    return winner;
}

//Compares the expected and actual result from input and output file
void assertEquals(string expected, string actual){
    if(expected == actual) cout<<"TEST CASE PASSED"<<endl;
    else cout<<"TEST CASE FAILED"<<endl;
}

//Driver code
int main(){
    string str;
    fstream inputFile;
    inputFile.open("givenInput.txt", ios :: in);

    if(inputFile.is_open()){
        while(getline(inputFile, str)){
            numbers.push_back(stoi(str));
        }
    }

    string actualResult;
    fstream outputFile;
    outputFile.open("expectedOutput.txt", ios :: in);
    getline(outputFile, actualResult);


    int winner = tournament(numbers);
    if(winner){
        string expectedResult = "Player "+to_string(winner)+" won the game. Final Score: "+to_string(firstPlayerPoints)+"-"+to_string(secondPlayerPoints);
        cout<<"Player "<<winner<<" won the game. Final Score: "<<firstPlayerPoints<<"-"<<secondPlayerPoints<<endl;
        assertEquals(expectedResult, actualResult);
    }
    else{
        string expectedResult = "There is a draw. Final Score: "+to_string(firstPlayerPoints)+"-"+to_string(secondPlayerPoints);
        cout<<"There is a draw. Final Score: "<<firstPlayerPoints<<"-"<<secondPlayerPoints<<endl;
        assertEquals(expectedResult, actualResult);
    }

    //close all files
    inputFile.close();
    outputFile.close();

    return 0;
}
