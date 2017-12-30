/************************************************************************************************************
A linked list is a collection of components call node. Each node stores an element and an adress to the next node, the last node points to nothing thus it is null.

This is my first linked list project. Various functions will be apply here such as creat the list, travel the list, print the list in different order, etc.

************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//there about 4 ways to place and struct and pointers
struct Node
{
	int data;
	Node *next;
};
class LinkedList
{
	Node *head = NULL;
	Node *connect = NULL;
public:

	void CreateList(int);//function to create the list
	void Display();//to show the elements in the list
	void Add(int, int,int);//add a number to the list to a specific position
	void Delete(int);//delete a node in a specific position
};

void LinkedList::CreateList(int n)
{
	//Node *connect = NULL; cant place cnnect and head here, because every time when the function is called, head and connect are set to null
	Node *newnode = new Node;
	newnode->data = n;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
		connect = newnode;
	}
	else
	{
		connect->next = newnode;
		connect = newnode;
	}
}

void LinkedList::Display()
{
	Node *show = head;
	while (show != NULL)
	{
		cout << show->data << " ";
		show = show->next;
	}
	//connect = head;//maybe this will put connect back to the begining of the list
}

void LinkedList::Add(int size,int position, int number)
{
	//3 posibiities, add to the 0th poisition, last position, and somewhere between
	Node *newnode = new Node;//create a new node every time the function is called
	newnode->data = number;

	if (position == 0)//add to the begining
	{
		newnode->next = head;
		head = newnode;//put head back to the begining of the list
	}
	else if (position > size)//add it as the last node
	{
		Node *connect2 = head;
		newnode->next = NULL;
		while (connect2->next != NULL)
			connect2 = connect2->next;
		connect2->next = newnode;//connect->next is NULL, but now it points to newnode->next

	}
	else//add the number to anywher between 
	{
		Node *connect3 = head;
		for (int x = 0; x < position - 1; x++) connect3 = connect3->next;
		newnode->next = connect3->next;
		connect3->next = newnode;
	}
}

void LinkedList::Delete(int position)
{
	Node *connect4 = head;
	if (position == 0) head= head->next;//first node lost connection.. this one works, 

	for (int x = 0; x < position - 1; x++) connect4 = connect4->next; 
	connect4->next = connect4->next->next;//simply make that node disconect from the list
}
int main()
{
	LinkedList lo;
	int size, n;
	cout << "Enter the size of the list you want to created--";
	cin >> size;
	for (int x = 0; x < size; x++)
	{
		cin >> n;
		lo.CreateList(n);
	}
	cout << "The list contains--";
	lo.Display();
	cout << endl;

	cout << "Enter how many numbers you want to add into the list--";
	int numbers;
	cin >> numbers;
	cout << "Enter the position and the number you wish to insert the number--";
	int position, number;
	for (int x = 0; x < numbers; x++)
	{
		cin >> position >> number;
		lo.Add(size,position, number);
	}

	cout << "The new list contains--";
	lo.Display();
	cout << endl;

	cout << "Enter the position to remove from the list--";
	int position2;
	cin >> position2;
	lo.Delete(position2);
	
	cout << "The new list contains--";
	lo.Display();
	cout << endl;
	system("pause");

}
