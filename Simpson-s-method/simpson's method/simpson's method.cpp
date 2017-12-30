// simpson's method.cpp : Defines the entry point for the console application.
//
#include <cmath>
#include <iostream>
#include "stdafx.h"
using namespace std;

//area=dx/3*{f(x0)+4*f(x1)+2*f(x2).....4*f(xn-1)+f(xn)}

double a, b, n;//must put here so all functions can access it

double function(double x)//enter the function here
{
	return pow(x, 2) + 2 * x;//how to manually enter a function?
}
double fx1()//f(X0) and f(Xn)
{
	return function(a) + function(b);
}

double fx2()//4*f(xn) when n is odd start from 1,3,,,n-1, 
{
	double sum = 0;//better keep it because sum is in for loop
	double dx = (b - a) / n;
	double firstodd = a + dx;
	double firsteven = a+2*dx;
	double lasteven = b - 2 * dx;
	for (double odd = firstodd, even=firsteven; odd < b, even < lasteven; odd+=2*dx, even+=2*dx)
	{
		sum = sum + 4 * function(odd)+2*function(even);
	}
	return sum;
}
double answer()
{
	double dx = (b - a) / n;
	double dx2 = dx / 3;
	return dx2*(fx1() + fx2());
}
int main()
{
	cout << "Enter the a, b and n here." << endl;// a and b are the right and left side of the inter val
	cin >> a >> b >> n;	//n is how many intervals to cu //how do i tell it n must be even?
	double ans = answer();
	cout << ans;
	system("pause");
}


/* credit goes to this guy.
Problem 1 is the calculation of dx. A, b, and n are defined at file scope and therefore initialized to 0. 
dx is then calculated as (0-0)/0 which properly produces a nan. Move the calculation of dx into main (preferred)
or into answer.

Problem 2 is your comment formula for the area.  Your comment states you need dx/2 but you really need dx/3.  
Comments should aid understanding, not add to confusion.

Problem 3 is caused by abusing global variables.  In the vast majority of cases, they cause more problems than 
they solve.  In this case, each of your fx? functions uses sum.  Except for fx1, they do not clear it.  Consider 
the case where a = 4, b = 5, and n = 6.  dx is obviously 1/6.  Let x0 denote a+0*dx = a, x1 denote a+1*dx, x2 denote
x+2*dx, ..., and x6 denote a+6*dx = b.
After fx1 executes, sum = f(x0)+f(x6).  This is the value fx1 returns
After fx2 executes, sum = f(x0)+f(x6) + 4*(f(x1)+f(x3)+f(x5)).  This is the value fx2 returns.  Note that there is an 
extra f(x0)+f(x6).
After fx3 executes, sum = f(x0)+f(x6)+4*(f(x1)+f(x3)+f(x5)) + 2*(f(x2)+f(x4)).  Note the extra terms.
Answer then computes dx2 * (fx1+fx2+fx3).  Ignoring the dx2 term for the moment, that parenthetical expression is
[f(x0)+f(x6)] + [f(x0)+f(x6)+4*(f(x1)+f(x3)+f(x5)] + [f(x0)+f(x6)+4*(f(x1)+f(x3)+f(x5))+2*(f(x2)+f(x4))]
Combining like terms we get
3*(f(x0)+f(x6)) + 8*(f(x1)+f(x3)+f(x5)) + 2*(f(x2)+f(x4))

Comparing this to your desired formula, it is obvious that
The first coefficient is wrong.  It should be 1, not 3.
The second coefficient is wrong.  It should be 4, not 8.

The easiest solution is to remove the global variable sum and define a local variable sum in each of fx1, fx2, 
and fx3.  Be sure to initialize it to zero in each function.
*/