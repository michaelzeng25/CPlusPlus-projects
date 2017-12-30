#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
/*
A simple program that is used to help myself to understand hash table.

The program reads information from a txt file and store the information in the hash table.

In this case, name and address.

At the run time, enter a name to find its address, if not found in the hash table, it will say not found

After comparing whther to use linked list or linear probing to handle collision. I think linked list is much better.




*/

struct Table
{
	string name;
	string address;
	Table *next=NULL;//end of the linked list is set to null
};

class Hashing
{
    static const int ini_size = 100;//the array has a capacity of 100, I wonder how to 
	Table *CreateTable[ini_size];//array of pointers
	vector<int> v;//will be used to hold all the hash values

public:
	Hashing( int &);//initialize the hash table
	void HashFunc(vector<string>&, int &);//colllect the hash values
	void HashTable(vector<string> &, vector<string> &, int &);//create the hash table
	void Show(string &, int &);//enter a name and get the address
};

Hashing::Hashing( int &size)
{
	for (int x = 0; x < size; x++)
	{
		CreateTable[x] = new Table;//will create size number of new Table instead of 100 but maybe willl not use all these new tables because of hash value
		CreateTable[x]->name = " ";
		CreateTable[x]->address = " ";
		CreateTable[x]->next = NULL;
	}
}

void  Hashing::HashFunc(vector<string> &names, int &size)
{
	for (int x = 0; x < size; x++)//
	{
		int sum = 0, HashValue = 0;
		for (int y = 0; y < names[x].size(); y++)
		{
			sum += (int)names[x].at(y);//sum up the values of each char in a name
		}
		HashValue = sum % size;//
		v.push_back(HashValue);//push the hash values into the vector
	}
}

void Hashing::HashTable(vector<string> &names, vector<string> &addresses, int &size)
{
	for (int x = 0; x < size; x++)
	{
		if (CreateTable[v[x]]->name == " ")//if the node is unoccupied
		{
			CreateTable[v[x]]->name = names[x];//placing the first name and address into the first hash table. v[x] is the hash value for name[x]
			CreateTable[v[x]]->address = addresses[x];
		}
		else//collision occur
		{
			Table *travel = CreateTable[v[x]];//using the travel pointer to travel the list to add more elements for this specific list, every list will have its own travel pointer
			Table *newpt = new Table;//creating a new node to hold up the new information
			newpt->name = names[x];
			newpt->address = addresses[x];
			newpt->next = NULL;
			while (travel->next != NULL)
				travel = travel->next;
			travel->next = newpt;//connect the node to the previous one in the same list
		}

	}

}
void Hashing::Show(string &target, int &size)
{
	//convert that name into hash value and find it in the hash table
	int sum = 0;
	for (int x = 0; x < target.length(); x++)
		sum += int(target[x]);
	int HashValue = sum % size;

	for (int x = 0; x < size; x++)
	{
		if (HashValue == v[x])//if the hash value of the target matches one of the hash values in the table
		{
			if (target == CreateTable[v[x]]->name)//good if the list has only one node, then the names must be the same
			{
				cout << CreateTable[v[x]]->address << endl;
				return;//found it and break out the loop
			}
			else//uh-oh....name does not match, so has to travel the list to find the one that matches the name
			{
				Table *travel = CreateTable[v[x]];//create a pointer for that list and travel in it
				while (travel->next != NULL)//travel to the end//changed travel to travel->next to fix the pointer problem that crash the program
				{
					travel = travel->next;
					if (travel->name == target)//if the name matches
					{
						cout << travel->address << endl;
						return;
					}
				}
			}
		}
	}
	cout << "Not in the table" << endl;

}
int main()
{	
	ifstream infile;
	infile.open("info.txt");//first line is name, second line is the address, and repeat
	//get how many lines in the file
	string checkline;
	int countline = 0;
	vector<string> names;
	vector<string> addresses;
	while (getline(infile, checkline))//read the entire file empty line could be between not empty lines
	{
		countline++;// even nuber in the end
		if (countline % 2 ==1)//name is in every line that is odd--NOOOOO ==0 is correct somehow.
			names.push_back(checkline);//push the name into the name vector
		else if(countline %2 ==0)
			addresses.push_back(checkline);//push the adress into the address vector
	}
	int size = countline / 2;//countline=total lines, name and address will be put together so half of the size is enough.
	Hashing Ho(size);
	// have all the names in the name vector and all the address in the address vector, and the index in the vector for them should be the same
	Ho.HashFunc(names,size);
	Ho.HashTable(names, addresses, size);
	//enter the name and display the adress

	string TargetName;
	while (TargetName != "end")
	{
		cout << "Enther the name to find the address or enter end to quit-- ";
		getline(cin, TargetName);
		if (TargetName == "end") break;
		Ho.Show(TargetName, size);
		cout << endl;
	}

	system("pause");


}
