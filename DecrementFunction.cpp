/*
 This is a simple program that starts at one number and
 decrements at the second number. Enter the starting number
 first and the decrement number second with a space in between.
 Cleveland Martin IV
*/
#include <stdio.h>
#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
using namespace std;

void descendingPrint(int start, int frequency)
{
    
    if (start >= 0 || start - frequency >= 0)
    {
        cout<< start << " ";
        descendingPrint(start - frequency, frequency);
    }
    else if (start < 0)
    {
        return;
    }
}


int main()
{
    int st;
    int fr;
    cin >> st >> fr;
    descendingPrint(st, fr);
}

