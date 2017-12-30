#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

/*******************************************************************************************************
for addition and subtraction, the matrices must be the same size.
1 2    +     2 3    =3 5
3 4          4 5     7 9
for multiplication and division, the number of column of the first matrix must be the same as the number of row of the second matrix. the new matrix will have a row size of the first matrix
and column size of the second matrix
1 2 3   *     2 3    = 2x3 * 3x2 = 28 34
3 4 5         4 5                  52 64
6 7
problem: out of range for 2x3 and 3x2
******************************************************************************************************/


class matrix
{
	vector<vector<int> > v;//use int variables to make life easier
	int RowSize; //row size
	int ColumnSize; //column size

public:
	matrix(int, int);//constructor with 2 arguments
	matrix(void) {};//constructor for mo3 
	~matrix(void) {};//destructor
	matrix operator+ (const matrix&);//to get a new matrix, operatot overloading is needed
	matrix operator- (const matrix&);
	matrix operator * (const matrix&);

	friend ostream& operator<<(ostream&, const matrix&);//overload the cout
	friend istream& operator >> (istream&, matrix&);//overload the cin
};

matrix::matrix(int R, int C)//initialize the matrix by setting all elements =0. this happens after entering the sizes of the 2 matrices
{
	RowSize = R;
	ColumnSize = C;

	//row
	for (int i = 0; i<R; i++)
	{
		vector<int> row;
		v.push_back(row);
	}
	//column   faster then using nested for loops
	int r = 0;
	int count = 0;
	while (r<R)
	{
		v[r].push_back(0);
		count++;//1 then 2
		if (count == C)//2=2 if C=2
		{
			r++;
			count = 0;//move to next row, so count start from 0
		}
	}
}

istream& operator >> (istream& is, matrix& m)//inputing the elements in the matrices
{
	int r = 0;
	int c = 0;
	int count = 0;
	while (r < m.RowSize)
	{
		is >> m.v[r][c];
		c++;
		if (c == m.ColumnSize)
		{
			r++;
			c = 0;//move to next row 
		}
	}
	return is;
}


matrix matrix :: operator+ (const matrix& m)//after inputting the eements of the 2 matrices, overloading starts here
{
	matrix answer(RowSize, ColumnSize);
	int r = 0;
	int c = 0;
	while (r < m.RowSize)
	{
		answer.v[r][c] = v[r][c] + m.v[r][c];
		c++;
		if (c == m.ColumnSize)
		{
			r++;
			c = 0;//move to next row 
		}
	}
	return answer;
}

matrix matrix :: operator- (const matrix& m)
{
	matrix answer(RowSize, ColumnSize);
	int r = 0;
	int c = 0;
	while (r < m.RowSize)
	{
		answer.v[r][c] = v[r][c] - m.v[r][c];
		c++;
		if (c == m.ColumnSize)
		{
			r++;
			c = 0;//move to next row 
		}
	}
	return answer;
}


matrix matrix :: operator* (const matrix& m)
{
	// if the input is 2x3 and 3x2, what is m.rowsize = to? the first one or the last one?
	matrix answer(RowSize, m.ColumnSize);//every result of matrix operations will produce new matrix with this size
	//Rowsize=rowsize of the first entered matrix, m.rowsize will be the second entered matrix
	int r = 0;
	int c = 0;
	int r1 = 0;
	int c1 = 0;
	int r2 = 0;
	int c2 = 0;
	int count = 0;
	while (r < RowSize)
	{	//v would be the first entered matrix, and m.v should be the second one.
		answer.v[r][c] += v[r1][c1] * m.v[r2][c2];
		c1++;
		r2++;
		count++;
		if (count == m.RowSize)
		{
			c++;
			c1 = 0;
			r2 = 0;
			c2++;
			count = 0;
			if (c == m.ColumnSize)
			{
				r++;
				r1++;
				c = 0;
				c2 = 0;
			}
		}
	}
	return answer;
}


ostream& operator <<(ostream& os, const matrix& m)//outputing the new matrix
{
	int r = 0;
	int c = 0;
	int count = 0;
	while (r < m.RowSize)
	{
		os << m.v[r][c] << " ";
		c++;
		count++;
		if (count == m.ColumnSize)
		{
			r++; //next row
			count = 0;
			c = 0;
			os << endl;
		}
	}
	return os;
}

int main()
{

	while (1)
	{
		int c;
		cout << "Enter 1 to continue or 0 to quit" << endl;
		cin >> c;
		if (c == 0) break;

		while (c != 0)
		{
			int rs, cs;//row size, column size, 
			cout << "Enter the size of the first matrix, row and then column-, ";
			cin >> rs >> cs;

			int rs2, cs2;
			cout << "Enter the size of the second matrix, row and then column-";
			cin >> rs2 >> cs2;

			if (rs2 == rs && cs2 == cs)//for addition and subtraction, size of matrix must be the same, * and / are both ok
			{
				int op;
				cout << "chose 1=+, 2=-, 3=*, or enter 0 to go back to he begining to re-enter the sizes" << endl;
				cin >> op;
				if (op == 0) break;

				matrix mo1(rs, cs);//mo=matrix object
				cout << "Enter the elements of the first matrix." << endl;
				cin >> mo1;//operator >> overloading

				matrix mo2(rs2, cs2);
				cout << "Enter the elements of the second matrix." << endl;
				cin >> mo2;

				matrix answer;//return the answer

				switch (op)
				{
				case 1:
				{
					answer = mo1 + mo2;
					cout << "The new matrix afte + is:" << endl;
					cout << answer << endl;//operator << overloading
					break;
				}
				case 2:
				{
					answer = mo1 - mo2;
					cout << "The new matrix afte - is:" << endl;
					cout << answer << endl;
					break;
				}
				case 3:
				{
					answer = mo1 * mo2;
					cout << "The new matrix afte - is:" << endl;
					cout << answer << endl;
					break;
				}
			
				default: break;
				}
				break;//break this while loop and go back to ask enter 1 or 0
			}
			else if (rs2 != rs || cs2 != cs)//for only * and /
			{
				int op;
				cout << " size issue, cant perform - and +, only *, enter 1 to continue or 0=go back to beining" << endl;
				cin >> op;
				if (op == 0) break;

				matrix mo1(rs, cs);//mo=matrix object
				cout << "Enter the elements of the first matrix." << endl;
				cin >> mo1;//operator >> overloading

				matrix mo2(rs2, cs2);
				cout << "Enter the elements of the second matrix." << endl;
				cin >> mo2;
				//if?rs<rs2) the new matrix will be the size of rs x cs2
				//if(rs>rs2) the size of the new matrix is rs x cs2   same if size if not perfect, new size is rs x cs2
				matrix answer;//if input is 2x3 and 3x2, the new matrix should have a size of 2x2

					answer = mo1 / mo2;
					cout << "The new matrix afte + is:" << endl;
					cout << answer << endl;//operator << overloading
					break;
				
					answer = mo1 * mo2;
					cout << "The new matrix afte * is:" << endl;
					cout << answer << endl;
					
				break;//break this while loop and go back to ask enter 1 or 0
			}
		}//second while
	}//first hile
	system("pause");
}
