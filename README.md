# Problem Statement

```
A new game in carrom-board called Clean Strike is played by 2 players with multiple turns. A
turn has a player attempting to strike a coin with the striker. Players alternate in taking turns.

```
The game is described as follows:
* There are 9 black coins, a red coin and a striker on the carrom-board

* **Strike** - When a player pockets a coin he/she wins a point

* **Multi-strike** - When a player pockets more than one coin he/she wins 2 points. All, but 2 coins, that were pocketed, get back on to the carrom-board

* **Red strike** - When a player pockets red coin he/she wins 3 points. If other coins are pocketed along with red coin in the same turn, other coins get back on to the carrom-board

* **Striker strike** - When a player pockets the striker he/she loses a point

* **Defunct coin** - When a coin is thrown out of the carrom-board, due to a strike, the player loses 2 points, and the coin goes out of play

* When a player does not pocket a coin for 3 successive turns he/she loses a point
* When a player fouls 3 times (a foul is a turn where a player loses, at least, 1 point), he/she loses an additional point
* A game is won by the first player to have won at least 5 points, in total, and, at least, 3 points more than the opponent
* When the coins are exhausted on the board, if the highest scorer is not leading by, at least, 3 points or does not have a minimum of 5 points, the game is considered a draw


*Write a program that takes in the outcome of each turn as input and outputs the result of the game as and when applicable along with necessary statistics that supports the result. Please find sample input and output below:

Sample Input:
Player 1: Choose an outcome from the list below
1. Strike
2. Multistrike
3. Red strike
4. Striker strike
5. Defunct coin
6. None


> ``` 1 ```

Player 2: Choose an outcome from the list below
1. Strike
2. Multistrike
3. Red strike
4. Striker strike
5. Defunct coin
6. None

> ``` 6 ```

.

.

.

.

Player 1 won the game. Final Score: 15-11

# Steps to run this file:

* Download the repository
* Extract the folder in your local drive
* Open it with terminal

![Screenshot from 2021-11-01 00-55-55](https://user-images.githubusercontent.com/42698268/139598440-151f59f6-cdd6-4903-b7d5-e982bf74bde8.png)

* Now run the following command

>``` g++ game.cpp ``` for compilation of the program


![Screenshot from 2021-11-01 00-50-16](https://user-images.githubusercontent.com/42698268/139598347-311ed50c-8a1c-4c2c-b752-4a4c58d7cad4.png)


>``` ./a.out ``` to run the program


![Screenshot from 2021-11-01 00-50-33](https://user-images.githubusercontent.com/42698268/139598361-63572dda-eb22-4128-950c-726a2bc2e1df.png)

* This would be the final result


![Screenshot from 2021-11-01 00-50-48](https://user-images.githubusercontent.com/42698268/139598462-c35d7b40-90da-44c1-8639-0707c15a3ba2.png)

* We have a file called ```givenInput.txt```, in which you can provide required test cases and you can test the program on those test cases.

![Screenshot from 2021-11-01 01-07-51](https://user-images.githubusercontent.com/42698268/139598872-33faa88b-ebd3-46ce-8a94-e618a25d63f0.png)
 

* This program will automatically run on all the given inputs provided in the ```givenInput.txt``` file, and will print the required result

* For testing, we have a file ```expectedOutput.txt``` which will store the expected output of the test case given in the ```givenInput.txt```, and the assert function which is implemented inside the code will check whether the expected output is same as actual output or not, if both are same then it will print the statement "TEST CASE PASSED" else it will print "TEST CASE FAILED".

![Screenshot from 2021-11-01 01-08-16](https://user-images.githubusercontent.com/42698268/139598884-b35c376b-b654-4dbe-bbdc-5da19c284c01.png)



