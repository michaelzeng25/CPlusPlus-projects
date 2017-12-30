// binary search.cpp : Defines the entry point for the console application.
 #include <iostream>
using namespace std;

#include "stdafx.h"
void binary_search( int list[], int listlenth, int target)
{

	int firstnumber =0;
	int lastnumber = listlenth - 1;//these two tells the program to use the index number instead of the elements
	int mid;
	bool found = false;//
	while (firstnumber <= lastnumber && !found)
	{
		mid = (firstnumber + lastnumber) / 2;

		//if has already reached the target
		if (list[mid] == target)
			found = true;

		//if has not yet reach the target, then set up the new interals, 
		else if (list[mid] > target)
			lastnumber = mid - 1;
		else firstnumber = mid + 1;
	}
	cout << found? "It is in the location of "+mid : "not found";
	/*
	if (found)
	{
		cout << "it is in the location of " << mid;
		cout << endl;
	}
	else
		cout << "not in the list" << endl;
		*/
}

int main()
{
	int list[] = { 34,45,56,78,89 };
	binary_search(list, 5, 78);

	system("pause");
}

