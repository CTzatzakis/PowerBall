/*
 * @Copyright Copyright (C) 2020 Chris Tzatzakis
 * @license GNU/GPL http://www.gnu.org/copyleft/gpl.html
 * Company:		Chris Tzatzakis
 + Contact:		Chris.Tzatzakis@hotmail.com
 ^
 + Project: 	PowerBall
 * File Name:	main.h
 ^                              ***
 * Description: PowerBall Lottery Game Simulation
 *                              **
 * */

#include<iostream>
#include "functions.h"

using namespace std;

const int SIZE = 6;                     //The number of balls per ticket
const int waysToWin = 9;                //This is the range of the red balls

int main(int argc, const char * argv[])
{
    int tickets = displayMenu();        //Welcome screen lets you buy tickets
    int spending = tickets * 2;         //Charges you for the tickets
    int randomTickets[tickets][SIZE];   //Ticket number holders
    int randomPowerNumber[SIZE];        //Power ball numbers
    int arrayHolder[SIZE];              //Temporary ticket holder
    int ballCounter = 0;                //Keeps track of winning balls in a ticket
    bool redBall;                       //Keeps track if the red ball matches
    int cashWon = 0;                    //Cash won Accumalator
    int lost = 0;
    int winningTickets[waysToWin];

    /*
     The next set of instructions will randomly generates the first 5 white balls and
     the last ball is the red ball. White balls are 1-59 and the red ball are 1-35
     */

    cout<<"Powerballs: ";
    for(int i = 0; i<SIZE; i++)
    {
        randomPowerNumber[i] = randomNumber(MAX_WHITE);                     //Randomly generates a number 1-59
        while(checkArray(randomPowerNumber, i, randomPowerNumber[i]))       //If random number is in use generate another random number
        {
            randomPowerNumber[i] = randomNumber(MAX_WHITE);                 //Randomly generates a number 1-59
        }
        if(i == (SIZE - 1))                                                 //If the increment is the last one it is the red ball
        {
            randomPowerNumber[i] = randomNumber(MAX_RED);                   //So it generates a number 1-35
        }
        cout<<"["<<randomPowerNumber[i]<<"] ";                              //This displays the number at current increment
    }
    cout<<endl;

    cout<<"Your tickets\n";


    /*
     1. The first loop indicates the tickets
     2. the second loop indicates the numbers in the current ticket.
     3. The number of tickets is user defined.
     4. Generate random numbers for a ticket to simulate quick picks.
     */
    for(int i = 0; i < tickets; i++)
    {
        ballCounter = 0;                //Flag for all the numbers that match the white power balls
        redBall = false;                //Flag for redball match
        for(int j = 0; j < SIZE; j++)
        {
            arrayHolder[j] = randomNumber(MAX_WHITE); //randomWhiteNumber();               //This will generates a random number 1-59 at current location
            while(checkArray(arrayHolder, j, arrayHolder[j]))   //If number generated is in use enter while loop
            {
                arrayHolder[j] = randomNumber(MAX_WHITE); //randomWhiteNumber();           //Generate a random number for current location
            }
            if(j == (SIZE - 1))                                 //If current location is the red ball generate a number 1-35
            {
                arrayHolder[j] = randomNumber(MAX_RED); //randomRedNumber();
            }else{
                if(checkArray(randomPowerNumber, (SIZE-1), arrayHolder[j]))       //If current number generated is a white ball
                    ballCounter++;                                         //Check to see if the number is a powerball number if
            }                                                              //it matches increment ball counter
            randomTickets[i][j] = arrayHolder[j];                          //Stores number in ticket
            cout<<"["<<randomTickets[i][j]<<"] ";                          //Display number to screen
        }

        cout<<"\nWhiteballs match : "<<ballCounter<<" ";     //This displays the number of white balls that match the powerballs
        //White balls

        //This checks to see if the tickets redball matches the powerballs redball
        if(arrayHolder[SIZE - 1] == randomPowerNumber[SIZE-1])
        {
            cout<<"The red ball matches too!";
            redBall = true;
        }

        cashWon += won(ballCounter, redBall);       //This adds the cash won from the ticket to your cash fund


        //The following else if statements just keeps track of how many tickets of each level actually won
        if(ballCounter == 5 && redBall)
            winningTickets[0]++;
        else if(ballCounter == 5)
            winningTickets[1]++;
        else if(ballCounter == 4 && redBall)
            winningTickets[2]++;
        else if(ballCounter == 4)
            winningTickets[3]++;
        else if(ballCounter == 3 && redBall)
            winningTickets[4]++;
        else if(ballCounter == 3)
            winningTickets[5]++;
        else if(ballCounter == 2 && redBall)
            winningTickets[6]++;
        else if(ballCounter == 1 && redBall)
            winningTickets[7]++;
        else if(redBall)
            winningTickets[8]++;
        else
            lost++;
        cout<<endl;
    }
    //The folling code outputs to the user the number of tickets that won and display the number of losing tickets
    cout<<"You have "<<winningTickets[0]<<" tickets that is a grand prize winner"<<endl;
    cout<<"You have "<<winningTickets[1]<<" tickets winning $1,000,000"<<endl;
    cout<<"You have "<<winningTickets[2]<<" tickets winning $10,000"<<endl;
    cout<<"You have "<<winningTickets[3] + winningTickets[4]<<" tickets winning $100"<<endl;
    cout<<"You have "<<winningTickets[5] + winningTickets[6]<<" tickets winning $7"<<endl;
    cout<<"You have "<<winningTickets[7] + winningTickets[8]<<" tickets winning $4"<<endl;
    cout<<"You have "<<lost<<" losing tickets"<<endl;

    //The following code outputs how much money you spent and how much money you won
    cout<<"You spent $"<<spending<<endl;
    cout<<"You won $"<<cashWon<<endl;
}