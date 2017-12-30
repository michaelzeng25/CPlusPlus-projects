#include <iostream>
#include "stdafx.h"
using namespace std;

/******************************************************************************************
Newton's method

if Xn is an approximation solution for F(X)=0, and F'(x)!=0, then F(Xn+1)=Xn-F(Xn)/F'(Xn)

1, need a function
2, find its derivative

pick two points that are very close to the target, let the difference of the distance = h
we have  {(x-h) ,f(x-h)} to the left of x, and {(x+h) ,f(x+h)} to the right of x
use the slope formula to find the slope
f(x+h)-f(x-h)=f'(x)*{(x+h)-(x-h)}
after simplification, it becomes f'(x)={f(x+h)-f(x-h) }/2h


*******************************************************************************************/
double function(double x)//the function
{
	return  pow(x,3)+2*x+5;
}

double df(double x)//the derivative of the function
{
	const double h = 0.0000001;
	return (function(x + h) - function(x - h)) / (2 * h);
}

double result(double x)//the answer
{
	return x - (function(x) / df(x));

}
int main()
{
	cout << "";

	double x;
	cout << "enter x" << endl;
	cin >> x;//
	int count = 10;//output 10 values
	while(count--)
	{
		x = result(x);
		cout << x << " ";//this x will be placed into g(x), 
	}
	system("pause");
}

