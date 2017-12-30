#include<iostream>
#include<iomanip>
using namespace std;
/*************************************************************************************************
Assignment: write an programing for the complex number. 
In this program, use operator overloading to overload the - and + operator
the purpose is to get familiar with operator overloading
************************************************************************************/

class complex
{
	double real;
	double imagine;

public://constructor and destructor will be provided in default
	complex(double rl, double im) :real(rl), imagine(im) {};//constructor with 2 arguments
	complex operator +(const complex& ot);
	complex operator -(const complex& ot);
	friend ostream& operator<<(ostream&, const complex&);
};

ostream& operator<<(ostream& os, const complex& z)//output the first 2 instances
{
	os << z.real << " + ( " << z.imagine << ") i " << endl;
	return os;
}

complex complex::operator +(const complex& ot)//overload the + operator
{
	return complex(real + ot.real, imagine + ot.imagine);//real is the one from the first real i entered, ot.real is the second real i entered
}

complex complex::operator -(const complex& ot)//overload the - operator
{
	return complex(real - ot.real, imagine - ot.imagine);
}


int main()
{
	double n1, n2;
	cin >> n1 >> n2;
	complex co(n1, n2);
	cout << co;

	double n3, n4;
	cin >> n3 >> n4;
	complex co2(n3, n4);
	cout << co2;

	//operator overloading
	complex co3 = co + co2;
	cout << co3;

	complex co4 = co - co2;
	cout << co4;


	system("pause");
}
