/*
 * @Copyright Copyright (C) 2020 Chris Tzatzakis
 * @license GNU/GPL http://www.gnu.org/copyleft/gpl.html
 * Company:		Chris Tzatzakis
 + Contact:		Chris.Tzatzakis@hotmail.com
 ^
 + Project: 	PowerBall
 * File Name:	functions.h
 ^                              ***
 * Description: PowerBall Lottery Game Simulation
 *                              ***
 * */

#include<cstdlib>
#include<time.h>
#include <random>

using namespace std;

const int MAX_WHITE = 58;               //This is the range of the white balls
const int MAX_RED = 34;

std::random_device rd;
std::mt19937_64 gen(rd()% MAX_WHITE); //Standard mersenne_twister_engine seeded with random device or a specified number.
std::mt19937_64 gen2(rd()% MAX_WHITE);
/****************************************************************************
 *                          displayMenu()                                   *
 *    The displayMenu function outputs intro menu to screen and it allows   *
 *    The user to buy 1 to 250000 tickets                                   *
 ***************************************************************************/
int displayMenu()
{
    int tickets;
    cout<<"Powerball Simulator\n";
    cout<<"5 White Balls will be random generated and the last ball is red\n";
    cout<<"Each ticket cost $2\nEnter how many ticket will you like to buy: ";
    cin>>tickets;

    while((tickets <= 0 || tickets > 250000))
    {
        cout<<"Please enter a number between 1-1000: ";
        cin>>tickets;
    }
    return tickets;
}


int randomNumber(int ColorNum)
{
    /*
    std::random_device rd;
    std::mt19937_64 gen(rd()); //Standard mersenne_twister_engine seeded with random device or a specified number.
    std::uniform_real_distribution<> dis(0, 1);
    int output = (int)dis(gen)*ColorNum;
    return output; */

    int randomVar = (rand() % ColorNum)+1;
    return randomVar;

}

/****************************************************************************
 *                              checkArray()                                *
 *    This function will search through array[] for a number if  the number *
 *    is found then return true if it is not found return false             *
 ***************************************************************************/
bool checkArray(int array[], int size, int number)
{
    bool has = false;
    for(int i = 0; i< size; i++)
    {
        if(array[i] == number)
        {
            has = true;
        }
    }
    return has;
}
/****************************************************************************
 *                              won()                                       *
 *    This functions compare the number of balls that match in a ticket     *
 *    and returns the amount of cash the ticket is worth                    *
 ***************************************************************************/
int won(int ballCount, bool redBall)
{
    int cash = 0;
    switch(ballCount)
    {
        case 5:
            if(redBall)
                cash = 70000000;
            else
                cash = 1000000;
            break;
        case 4:
            if(redBall)
                cash = 10000;
            else
                cash = 100;
            break;
        case 3:
            if(redBall)
                cash = 100;
            else
                cash = 7;
            break;
        case 2:
            if(redBall)
                cash = 7;
            else
                cash = 0;
            break;
        case 1:
            if(redBall)
                cash = 4;
            else
                cash = 0;
            break;
        default:
            if(redBall)
                cash = 4;
            else
                cash =0;
            break;
    }
    return cash;
}

