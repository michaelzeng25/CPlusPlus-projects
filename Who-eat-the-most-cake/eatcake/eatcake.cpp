// eatcake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int people;
	vector <double> array;
	cout << "How many people.?" << endl;
	cin >> people;
	array.resize(people);
	for (int cake = 0; cake < people; cake++)//if people =3, then 1 to <= people should be ok, but not, 
	{
		cout << "Number of cake person " << cake << " ate is ";
		cin >> array[cake];

	}
	//ptint out the list




	//the one who eat the most and how many is eaten
	int largest = 0;
	for (double x = 1; x < people; x++)
	{
		if (array[largest] < array[x])
		{
			largest = x;//largest is replace by x and x is now the largest index
			//this is the part to print out the index which is the person who ate the most
		}
	}
	cout << "person " << largest << "  ate " << array[largest] << " cakes" << endl;

	system("pause");
	//i can use inertion sort to fnd the most eaten number of cake, but i have difficuty to print out who eat the most

}