/*
  This program will determine if a number is prime, it's least prime factor,
  its prime factorization, and the radical of the number.
  Cleveland Martin IV
 */
 
#include <iomanip>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
using namespace std;

/*
 Gives the least prime factor
*/
long lpf(long num)
{
    if(num < 2)
    {
        return -1;
    }
    else
    {
        int i;
        int x = 2;
        int n = num;
        for(i=2; (n%i)!=0; i++)
        {
            x++;
        }
        return x;
    }
}

/*
 Compute the radical of the specified number and generate
 its prime factorization.
*/
void factorize(long num)
{
    long int f = lpf(num);
    long int fr = lpf(num);
    string s;
    long int res = num;
    long int resr = num;
    long int r = 1;
    long int count = 0;
    cout<<"Prime Decomposition: "<<num<<" = ";
    if(num <= 0)
    {
        cout<<"nan"<<"\n";
        cout<<"radical ("<<num<<") = nan"<<"\n";
    }
    else if(num < 2)
    {
        cout<<"nan"<<"\n";
        cout<<"radical ("<<num<<") = "<<num<<"\n";
    }
    else if(num == lpf(num))
    {
        cout<<num;
    }
    else
    {
        while(res != 1)
        {
            while((res%f) == 0)
            {
                res = res/f;
                count++;
            }
            if(count == 1)
            {
                s = (to_string(f));
                if(res == 1)
                cout<<s;
                else
                cout<<s<<" x ";
            }
            else if(count >= 2)
            {
                s = (to_string(f)+'^'+to_string(count));
                if(res == 1)
                cout<<s;
                else
                cout<<s<<" x "; 
            }
            f++;
            count = 0;
        }
    }
    if(num > 1)
    {
        while(resr != 1)
        {
            while((resr%fr) == 0)
            {
               resr = resr/fr;
               if((resr%fr) != 0)
               {
                r = r*fr;   
               }
            }
            fr++;
        }
        cout<<"\n"<<"radical ("<<num<<") = "<<r;
    }
}
int main()
{
    long int num;
    cout<<"Enter a positive integer -> ";
    cin>>num;
    if(lpf(num) == -1)
    {
    cout<<"lpf("<<num<<") = nan"<<"\n";
    }
    else
    {
    cout<<"lpf("<<num<<") = "<<lpf(num)<<"\n";
    }
    long int lpft = lpf(num);
    if(num == lpft)
    {
        cout<<"?isPrime("<<num<<") = true"<<"\n";
    }
    else if(num<2)
    {
        cout<<"?isPrime("<<num<<") = false"<<"\n";
    }
    else
    {
        cout<<"?isPrime("<<num<<") = false"<<"\n";
    }
    factorize(num);
    return 0;
}
