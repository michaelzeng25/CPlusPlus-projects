// trapezoid.cpp : Defines the entry point for the console application.
#include <iostream>
#include "stdafx.h"
#include <cmath>
using namespace std;
//area=dx/2*{f(x0)+2*f(x1)+.....2*f(xn-1)+f(xn)}

double a, b, n;//a and b are the borders of the interval, n is number of sub intervals

double function(double x)//enter the function here
{
	return pow(x, 2) + 2 * x;//function(x)=x^2 +2x
}

double fx1()
{
	double sum= function(a) + function(b);//find the sum of the 2 f(x) that are not multiply by 2
	return sum;
}

double fx2()//here calculate those f(x) that are * by 2
{
	double dx = (b - a) / n;
	double x1 = a + dx;
	double sum = 0;
	for (double y = x1; y < b; y += dx)//if interval is = 2,4,6,8, then here takes 4,6 
	{
		sum = sum + 2*function(y);//get 2f(x1)+2f(x2)+......2f(Xn-1) here
	}
	return sum;
}
double result()
{
	double dx = (b - a) / n;
	return (dx / 2 )* (fx1() + fx2());
}

int main()
{
	double answer,x;
	cout << "Enter the a, b and n here." << endl;// a and b are the right and left side of the inter val
	cin >> a >> b >> n;	
	//n is how many intervals to cut
	cout << "The area is "<<result()<< endl;
	system("pause");
}

