/*
 This is the classic fizz, buzz computer science problem. 
 In one line, input the number to divide, then the step 
 count number (2 means we count 2, 4, 6, etc.), and then
 input divisor one and divisor 2. Every number must have a
 space between the lines. If the number is divisible 
 by 42, it will output "Answered," and not fizz or buzz. If
 the number is divisible by the first divisor, "Fizz" will
 be outputted. If the number is divisible by the second 
 divisor, "Buzz" will be outputted. If it is divisible by both,
 then "FizzBuzz" will be outputted.
 Cleveland Martin IV
*/
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <stdio.h>
using namespace std;



void fizzbuzzy(int max, int step, int divisorOne, int divisorTwo)
{
    if (max < 1)
    {
        cout<<"Bad Input"<<endl;
    }
    
    else if (step < 1)
    {
        cout<<"Bad Input"<<endl;
    }
    
    else if (divisorOne < 2)
    {
        cout<<"Bad Input"<<endl;
    }
    
    else if (divisorTwo < 2)
    {
        cout<<"Bad Input"<<endl;
    }
    
    else if (divisorOne == divisorTwo)
    {
        cout<<"Bad Input"<<endl;
    }
    
    else
    {
        int n=1;
        cout<<n<<endl;
        int i;
        for (i=max; i>1; i--)
        {
            n = n + step;
            
            if (n <= max)
            {
                if (n % 42 == 0)
                {
                    cout<<"Answered"<<endl;
                    i = 0;
                }
                
                else
                {
                    if((n % divisorOne == 0) || (n % divisorTwo == 0))
                    {
                        if (n % divisorOne == 0)
                        {
                            cout<<"Fizz";
                        }
            
                        if (n % divisorTwo == 0)
                        {
                            cout<<"Buzz";
                        }
                        cout<<endl;
                    }
                    
                    else
                    {
                        cout<<n<<endl;
                    }
                }
            }
        }
    }
}



int main()
{
    string inputString;
    getline(cin, inputString);
    istringstream ss(inputString);

    string tempVariable;
    
    ss >> tempVariable;
    int max = stoi(tempVariable);
    
    ss >> tempVariable;
    int step = stoi(tempVariable);
    
    ss >> tempVariable;
    int divisorOne = stoi(tempVariable);
    
    ss >> tempVariable;
    int divisorTwo = stoi(tempVariable);

    fizzbuzzy(max, step, divisorOne, divisorTwo);
}

