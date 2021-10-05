/*
* Create a class Game, which allows a user to play "Guess the Number" game once.
*/

package com.company;

import java.util.Scanner;
import java.lang.Math;

/*
* Game class for the Guessing game .....
* */
class Game{
    Scanner obj =new Scanner (System.in);

    private int noGuesses=0;
    private int random ;
    private int Max;

//// constructor of class Game.......
    public Game(){
        random = (int)(Math.random()*100+1);
        Max =15;
    }
//// Method to display Score........
    public int score () {
        noGuesses=getNoGuesses();
        if(Max<noGuesses)
            return 0;
        else
            return (Max - noGuesses);
    }

    // Method to get the Value of Random Variable....
    public int getRandom(){
        return random ;
    }

    // Method to get the Value of no of Guesses ....
    public int getNoGuesses(){
        return noGuesses;
    }

    // Method to get the Value of Maximum Attempts allowed .......
    public void setMax(){
        System.out.println("Max no of Attempts allowed: ");
        Max=obj.nextInt();
    }

//// Method to check whether user have Guessed right number or not ........
    public boolean isCorrectNumber(int userInput){
        return userInput == random;
    }

//// method to increment the no of guesses.........
    public void noOfGuesses() {
          noGuesses++;
    }
}
//// Our Main Class.........
public class GuessTheNumber {

    static Game game = new Game();      // Object of Game Class......
    static Scanner obj = new Scanner (System.in);

    public static void main(String[] args) {

        int score ;
        System.out.println("__________________Guess the Number Correctly__________________");
        System.out.println("Enter a number : ");
        int userInput = obj.nextInt();

//// loop to run the game till Max Attempts is not reached.......
        while (!game.isCorrectNumber(userInput)){
            game.noOfGuesses();         //Increments the number of guesses...

            if(userInput>game.getRandom())
                System.out.println("Error!! Bigger Number !! \ntry again ...");
            else System.out.println("Error!! Smaller Number !! \ntry again ...");

            userInput = obj.nextInt();
        }
        game.noOfGuesses();
        score = game.score();

        if(score==0)
            System.out.println("Oh No !!! \nYou Lose.....\nTry Again.. ");
        else
            System.out.println("Congratulation !!! \nYou Scored : "+score+" points.");
    }
}
