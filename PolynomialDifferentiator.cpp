/*
 This code will find the first, second, and third derivative
 of an entered polynomial. You must first enter how many terms are in
 the polynomial. Then you must enter the coefficients one at a time
 (type a number, click enter, type the next number, etc.). Lastly,
 you must enter the number that will be plugged into x in the polynomial.
 
 This project is one of my first as a freshman. This is not efficient, but it shows 
 what can be done on the surface level of C++ by problem solving.
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

string poly(int coeff[], int deg)
{
    int d = deg;
    string func = "";
    if(d==1)
    {
        if (coeff[0] == 1)
            func = "x";
        else if (coeff[0] == -1)
            func = "-x";
        else
            func = to_string(coeff[0]) + "x";
    }
    else if(d == 0)
    {
        func = to_string(coeff[0]);
        return func;
    }
    else
    {
        if (coeff[0] == 1)
            func = "x^" + to_string(d);
        else if (coeff[0] == -1)
            func = "-x^" + to_string(d);
        else
            func = to_string(coeff[0]) + "x^" + to_string(d);
    }
    d = deg - 1;
    for(int i=1; i<=deg; i++)
    {
        if (coeff[i]==0)
        d--;
        else
        {
            if(coeff[i]==-1)
            {
                if(d==1)
                {
                    func = func + " - x";
                }
                else if(d==0)
                {
                   func = func + " - " + to_string(coeff[i] * -1);
                }
                else
                func = func + " - x^" + to_string(d);
            }
            else if(coeff[i]==1)
            {
               if(d==1)
                {
                    func = func + " + x";
                }
                else if(d==0)
                {
                    func = func + " + " + to_string(coeff[i]);
                }
                else
                func = func + " + x^" + to_string(d);
            }
            else if(coeff[i]<-1)
            {
                if(d==1)
                {
                    func = func + " - " + to_string(coeff[i] * -1) + "x";
                }
                else if(d==0)
                {
                    func = func + " - " + to_string(coeff[i] * -1);
                }
                else
                func = func + " - " + to_string(coeff[i] * -1) + "x^" + to_string(d);
            }
            else if(coeff[i]>1)
            {
                if(d==1)
                {
                    func = func + " + " + to_string(coeff[i]) + "x";
                }
                else if(d==0)
                {
                     func = func + " + " + to_string(coeff[i]);
                }
                else
                func = func + " + " + to_string(coeff[i]) + "x^" + to_string(d);
            }
            d--;
        }
    }
    return func;
}

double eone(int coeff[], int deg, double x)
{
    double num = 0;
    int d = deg;
    if(deg == 1)
    {
        num = (coeff[0] * x) + coeff[1];
        return num;
    }
    else if(deg == 0)
    {
        num = coeff[0];
        return num;
    }
    else
    {
        for(int i=0; i<deg; i++)
        {
            num = num + (coeff[i] * pow(x, d));
            d--;
        }
        if(coeff[deg] != 0)
        {
            num = num + coeff[deg];
        }
        return num;
    }
}

string d1(int coeff[], int deg)
{
    string deriv;
    int d = deg;
    if (coeff[0] == 1)
    {
        if (d == 1)
        {
            deriv = to_string(d);
        }
        else if(d == 2)
        deriv = to_string(d) + "x";
        else if(d == 0)
        {
            deriv = "0";
            return deriv;
        }
        else
        deriv = to_string(d) + "x^" + to_string(d-1);
        d = d-1;
    }
    else if (coeff[0] == -1)
    {
        if (d == 1)
        {
            deriv = to_string(d);
        }
        else if(d == 2)
        deriv = to_string(d*-1) + "x";
        else if(d == 0)
        {
            deriv = "0";
            return deriv;
        }
        else
        deriv = to_string(d*-1) + "x^" + to_string(d-1);  
        d = d-1;
    }
    else if (coeff[0]>1)
    {
        if (d == 1)
        {
            deriv = to_string(coeff[0]);
        }
        else if(d == 2)
        deriv = to_string(coeff[0]*d) + "x";
        else if(d == 0)
        {
            deriv = "0";
            return deriv;
        }
        else
        deriv = to_string(coeff[0]*d) + "x^" + to_string(d-1);
        d = d-1;  
    }
    else if (coeff[0]<-1)
    {
        if (d == 1)
        {
            deriv = to_string(coeff[0]);
        }
        else if(d == 2)
        deriv = to_string(coeff[0]*d) + "x";
        else if(d == 0)
        {
            deriv = "0";
            return deriv;
        }
        else
        deriv = to_string(coeff[0]*d) + "x^" + to_string(d-1);
        d = d-1;  
    }
    for(int i=1; i<=(deg-1); i++)
    {
        if(d==1)
        {
            if(coeff[i] > 0)
            {
                deriv = deriv + " + " + to_string(coeff[i]);
            }
            else if(coeff[i] < 0)
            {
                deriv = deriv + " - " + to_string(coeff[i]*-1);
            }
        }
        else if(coeff[i] > 0)
        {
            if(d == 2)
            {
                deriv = deriv + " + " + to_string(coeff[i]*d) + "x";
            }
            else
            deriv = deriv + " + " + to_string(coeff[i]*d) + "x^" + to_string(d-1);
        }
        else if(coeff[i] < 0)
        {
            if(d == 2)
            {
                deriv = deriv + " - " + to_string(coeff[i]*d *-1) + "x";
            }
            else
            deriv = deriv + " - " + to_string(coeff[i]*d*-1) + "x^" + to_string(d-1);
        }
        d--;
    }
    return deriv;
}

double etwo(int coeff[], int deg, double x)
{
    double n;
    double num = 0;
    int d = deg;
    if(deg == 1)
    {
        num = num + coeff[0];
        return num;
    }
    else if(deg == 0)
    {
        return num;
    }
    else
    {
         for(int i=0; i<(deg-1); i++)
        {
            int j = (d-1);
            n = (coeff[i]*d)*(pow(x, j));
            num = num + n;
            d--;
            n = 0;
        }
        num = num + coeff[deg-1];
        return num;
    }
}

string d2(int coeff[], int deg)
{
    string deriv2;
    int d = deg;
    if (d == 0 || d == 1)
    {
        deriv2 = "0";
        return deriv2;
    }
    else if (d == 2)
    {
        if (coeff[0]==1)
        {
            deriv2 = "2";
            return deriv2;
        }
        else if (coeff[0]==-1)
        {
            deriv2 = "-2";
            return deriv2;
        }
        else if (coeff[0]<-1 || coeff[0]>1)
        {
            deriv2 = to_string(coeff[0]*2);
            return deriv2;
        }
    }
    else if (d>2)
    {
        if (d==3)
        {
            deriv2 = to_string(coeff[0]*(d-1)*d) + 'x'; 
        }
        else
        {
            deriv2 = to_string(coeff[0]*(d-1)*d) + "x^" + to_string(d-2);
        }
        for(int i=1; i<(deg-1); i++)
        {
            if (d-2 == 1)
            {
                if(coeff[i]>0)
                {
                    deriv2 = deriv2 + " + " + to_string(coeff[i]*(d-1));
                }
                if(coeff[i]<0)
                {
                    deriv2 = deriv2 + " - " + to_string(coeff[i]*(d-1)*-1);
                }
                return deriv2;
            }
            else if(coeff[i] > 0)
            {
                if((d-3) == 1)
                {
                    deriv2 = deriv2 + " + " + to_string(coeff[i]*(d-1)*(d-2)) + "x";
                }
                else
                {
                    deriv2 = deriv2 + " + " + to_string(coeff[i]*(d-1)*(d-2)) + "x^" + to_string(d-3);
                }
            }
            else if(coeff[i] < 0)
            {
                if((d-3) == 1)
                {
                    deriv2 = deriv2 + " - " + to_string(coeff[i]*(d-1)*(d-2)*-1) + "x";
                }
                else
                {
                    deriv2 = deriv2 + " - " + to_string(coeff[i]*(d-1)*(d-2)*-1) + "x^" + to_string(d-3);
                }
            }
            d--;
        }
    }
    return deriv2;
}



double e3(int coeff[], int deg, double x)
{
    double n;
    double num = 0;
    int d = deg;
    if(deg == 0 || deg == 1)
    {
        return num;
    }
    else
    {
        for(int i=0; i<(deg-2); i++)
        {
            int j = (d-2);
            n = (coeff[i]*d*(d-1))*(pow(x, j));
            num = num + n;
            d--;
            n = 0;
        }
        num = num + (coeff[deg-2]*2);
        
        
        
        return num;
    }
}


























int main()
{
    int degree;
    cout<<"Enter the degree of the polynomial -> ";
    cin>>degree;
    if (degree<0)
    {
        cout<<"Error: The degree of the polynomial must be nonnegative.";
        return 0;
    }
    int coefficients[degree];
    cout<<"Enter the degree coefficients -> ";
    for (int i=0; i<=degree; i++)
    {
        cin>>coefficients[i];
    }
    double xvalue;
    if (degree == 0 && coefficients[0] == 0)
    {
        cout<<"Enter the x at which f(x), f'(x), and f\"(x) will be evaluated -> ";
        cin>>xvalue;
        cout<<"\n"<<"f(x) = 0 \nf("<<xvalue<<") = 0\n";
        cout<<"\n"<<"f'(x) = 0 \nf'("<<xvalue<<") = 0\n";
        cout<<"\n"<<"f\"(x) = 0 \nf\"("<<xvalue<<") = 0\n";
        return 0;
    }
    else if (coefficients[0]==0)
    {
        cout<<"Error: Degree > 0 so the coefficient of the highest order term cannot be 0";
        return 0;
    }
    cout<<"Enter the x at which f(x), f'(x), and f\"(x) will be evaluated -> ";
    cin>>xvalue;
    cout<<"\nf(x) = "<<poly(coefficients, degree);
    cout<<"\nf("<<xvalue<<") = "<<setprecision(6)<<eone(coefficients, degree, xvalue)<<"\n";
    cout<<"\nf'(x) = "<<d1(coefficients, degree);
    cout<<"\nf'("<<xvalue<<") = "<<setprecision(6)<<etwo(coefficients, degree, xvalue)<<"\n";
    cout<<"\nf\"(x) = "<<d2(coefficients, degree);
    cout<<"\nf\"("<<xvalue<<") = "<<setprecision(6)<<e3(coefficients, degree, xvalue)<<"\n";
    

    return 0;
}







