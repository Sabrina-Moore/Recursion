// CSCI2 Moore recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
// CSCI 2 Homework 1
// Sabrina Moore

#include <iostream>
#include <string>
using namespace std;

int recursiveMult(unsigned int d, unsigned int f);
int getDigitCount(int num, int digit);
string doubleDollars(string n);
string findAngles(string str);
bool canEqualTarget(const int a[], int size, int target);
bool connectedPath(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);



int main()
{

}

//problem 1 -----------------------------------------------------------------------------


// Returns the product of two integers, d and f, using only repeated addition. The integers will always be positive.
int recursiveMult(unsigned int d, unsigned int f) //d + d + d f number of times
{
    if (f == 0)
        return 0;
    else
        return d + recursiveMult(d, f - 1); //(rM(3, 4) -> 3 + rM(3,3) -> 6 + rM (3,2) -> 9 + rM(3,1) -> 12 + rM(3,0) -> 12 equivalent to 3 + 3 + 3 + 3
}


//----------------------------------------------------------------------------
int getDigitCount(int num, int digit)
{
    if (num == 0)
        return 0;
    if (num % 10 == digit)
        return 1 + getDigitCount(num / 10, digit); //if digit found, increment counter
    else
        return getDigitCount(num / 10, digit); //if digit not found, continue but do not increase counter
}

// Returns a string where the same characters next each other in string n are separated by "$$". You can use substr in this problem
string doubleDollars(string n)
{

    if (n == "") //if n is empty
        return "";

    string symbol = "$$";
    char current = n[0];
    char next = n[1];

    if (current == next)
        return current + symbol + doubleDollars(n.substr(1)); //creates a new substring with current set to the first char
    if (current != next)
        return current + doubleDollars(n.substr(1)); //same thing, but does not add any symbol
}
//----------------------------------------------------------------------------

// str contains a single pair of angle brackets, return a new string made of only the angle brackets and whatever those angle brackets
// contain. You can use substr in this problem. You cannot use find.
string findAngles(string str)
{
    if (str == "") //base case for if there are no angle brackets
        return "";

    if (str.front() == '<' && str.back() == '>') //true base case for "<abc>" string so that when each recursive case gets to an angle bracket, it will hit this base case
        return str; ////beginning string char is < angle and ending string char is >

    // needs to recurse both directions, once one direction finds the angle bracket, it stops(so, checking str left to right until > , and checking str right to left until < )
    if (str.front() != '<')
        return findAngles(str.substr(1)); //creates new string where element 1 is now element 0 (erasing the first element)

    if (str.back() != '>')
        return findAngles(str.substr(0, str.size() - 1)); //creating a new string removed the last element of the string
}
//----------------------------------------------------------------------------

// Return true if the sum of any combination of elements in the array a equals the value of the target.
bool canEqualTarget(const int a[], int size, int target)
{
    if (target == 0) //accounting for a function call where the target is 0
        return true;
    if (size == 0) //base case
        return false;

    //must check combinations without the last element || checks combos with the last element 
    //size must shrink so that it hits base case
    //returns true = combination does equal target
    //returns false = does not equal target


    //if statement method - bool must return true or false
    if (canEqualTarget(a, size - 1, target)) //if the combination of values in the array except for the last element sum to the target
        return true;
    if (canEqualTarget(a, size - 1, target - a[size - 1]))//if the combinations including the last element sum to the target
        return true;
    else
        return false;


    //alternate method 
    //return canEqualTarget(a, size - 1, target)|| canEqualTarget(a, size - 1, target - a[size - 1]);
}
//----------------------------------------------------------------------------
//problem 2

// Return true if there is a path from (sr,sc) to (er,ec) through the maze; return false otherwise
//checks each direction, starting with north to see if it is a '.'
//marks the row and column position so it does not need to be checked again

bool connectedPath(string maze[], int nrRows, int nCols, int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec) //if starting position is ending position
        return true;

    if (maze[sr][sc] != '.') //if starting position is not clear
        return false;

    maze[sr][sc] = 'v'; //marking visited path

    if (connectedPath(maze, nrRows, nCols, sr - 1, sc, er, ec)) //checking north
        return true;
    if (connectedPath(maze, nrRows, nCols, sr, sc + 1, er, ec)) //checking east
        return true;
    if (connectedPath(maze, nrRows, nCols, sr + 1, sc, er, ec)) //checking south
        return true;
    if (connectedPath(maze, nrRows, nCols, sr, sc - 1, er, ec)) //checking west
        return true;
    else //nowhere to go, no connected path
        return false;
}




