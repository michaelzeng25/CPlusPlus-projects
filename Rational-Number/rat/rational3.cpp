#include <iostream>
#include <cstdlib>
using namespace std;
/*********************************************************************
long GCD(long a, long b)//
{
while (1)
{
a = a % b;
if (a == 0)
return b;

b = b % a;
if (b == 0)
return a;
}
}

totally forgot what professor told me about the significant of this part of code
**********************************************************************/

class rational
{
	long GCD(long a, long b)//
	{
		while (1)
		{
			a = a % b;
			if (a == 0)
				return b;

			b = b % a;
			if (b == 0)
				return a;
		}
	}
	
 public:
        long numer;
        long denom;
		rational() {};
		rational(long n, long d) : numer(n / GCD(n, d)), denom(d / GCD(n, d)) {};
        
    
rational operator +(const  rational& other)
		{

			return rational(numer*other.denom + denom*other.numer, denom*other.denom);
		}


 rational operator -(const  rational& other)
        {
            
            return rational(numer*other.denom-denom*other.numer,denom*other.denom);
    }
rational operator *(const  rational& other)
        {
            
            return rational(numer*other.numer,denom*other.denom);
    }

    
 rational operator /(const  rational& other)
        {
            
            return rational(numer*other.denom,denom*other.numer);
    }

 rational operator ^(int n)
        {
            rational x(numer,denom);
			rational answer(1,1);
			for(int i = 1;i<=n;i++)
				answer = answer*x;

            return answer;
    }
    
  void show()
    {
        cout<<numer<<"/"<<denom<<endl;
    }  
};

int main()
{

	long n1,n2,d1,d2;//numerator and denominator
	cout<<"Enter 2 rational numbers"<<endl;
	cin>>n1>>d1>>n2>>d2;

		if (d1 == 0 || d2==0)
		{
			cout << "Cant divide by 0" << endl;
			return 0;
		}

    rational r1(n1,d1);
    rational r2(n2,d2);
	cout<<"Choose your operations (0=+, 1=-,2=* ,3 = / , 4 = ^"<<endl;
	int op;//operation
	rational r3;//to perform operator overloading
	cin>>op;
	switch (op)
	{
	case 0:
		r3 = r1 + r2;
		break;
	case 1:
		r3 = r1 - r2;
		break;
	case 2:
		r3 = r1*r2;
		break;
	case 3:
		r3 = r1 / r2;
		break;
	case 4:
	{
		int  n;
		cout << "Enter an exponent " << endl;
		cin >> n;
		r3 = r1^n;
		break;
	}
	}
	r3.show();//output the answer

	
    system("pause");
    
}
