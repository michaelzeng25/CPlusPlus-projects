
/*
You are given  integer sequences N and Q queries.Each query is in the following format : "a,b " where a denotes the index of the sequence, and b denotes
the index of the element in that sequence.Your task is to find the value of the element described in each query.

Input Format
The first line consists of  and  separated by a space.
The following  lines contain sequences in this format: "    "
The following  lines contain queries in this format : " ".
*/
#include <string>
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> vec;
	int b;
	int sum = 0;
	int N, Q;
	cin >> N;//> Q;//number of sequence and queries
	cin >> b;
	int **pointer =new int *[N];//created N int pointers, *int--*int--*int--*int--*int....so on
	for (int x = 0; x < N; x++)//eg, n=5
	{


		*(pointer + x) = new int[b];//each of the 5 pointers point to an array of size b, for example, if x =0, it will be the first pointer with b elements in it
		for (int y = 0; y < b; y++)
		{
			cin >> pointer[x][y];//input the elements for each array


		}
	}
	sum = pointer[0][0] + pointer[1][0];
			vec.push_back(sum);
			sum = 0;
	
cout << vec[0];
	//merge the vlists
	
	/*
	//input which sequence and element to find and output the answer
	for (int q = 0; q < Q; q++)
	{
		int l,k;
		cin>>l>> k;//index number for which element
		cout << pointer[l][k] << endl;//output the answer
	}
	*/
	system("pause");
}

//if queries is > sequence
//if search index is out of the range
//add if statement