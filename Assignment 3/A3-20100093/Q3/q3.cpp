#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <iterator> 
#include <utility>
using namespace std;
/*
Time Complexity = O(n*n)
Space Complexity = O(n*n)
Recurrence Relation:
T(n) = 4T(n/2) + c
T(n) =  n^2 + n^2
T(n) = O(n^2)
*/
int n;
char start = 65;
void q3(char** Array, int size, int start_row, int start_col, int ins_row, int ins_col)
{
	
	if (size == 2) //Base case
	{
		int counter = 0;
		for (int i = start_row; i < start_row+size; ++i)
		{
			for (int j = start_col; j < start_col + size; ++j)
			{
				if (Array[i][j]=='-')
				{
					Array[i][j] = start;
					counter++;
					

				}
				if (counter==3)
				{
					start++;
					return;
				}
			}
		}
	}
	else
	{
		int center_row = start_row + size/2;
		int center_col = start_col + size/2;

		if (ins_row < center_row && ins_col < center_col) //top left
		{
			if (Array[center_row][center_col] == '-' && Array[center_row][center_col-1] == '-' && Array[center_row-1][center_col] == '-')
			{
				Array[center_row][center_col] = start;
				Array[center_row][center_col-1] = start;
				Array[center_row-1][center_col] = start;
				start++;
				q3(Array,size/2,start_row,start_col,ins_row,ins_col); //topleft

				q3(Array,size/2,start_row+size/2, start_col+size/2,center_row, center_col); //bottom right
				q3(Array,size/2,start_row+size/2, start_col,center_row, center_col-1); //bottom left
				q3(Array, size/2,start_row, start_col + size/2, center_row-1, center_col); // Top Right
				
				
			}
			
		}

		if (ins_row >= center_row && ins_col < center_col) //bottom left
		{

			if (Array[center_row][center_col] == '-' && Array[center_row-1][center_col] == '-' && Array[center_row-1][center_col-1] == '-')
			{
			
				Array[center_row][center_col] = start;
				Array[center_row-1][center_col] = start;
				Array[center_row-1][center_col-1] = start;
				start++;

				q3(Array,size/2,start_row,start_col,center_row-1,center_col-1); //topleft
				q3(Array,size/2,start_row+size/2, start_col+size/2,center_row, center_col); //bottom right

				q3(Array,size/2,start_row+size/2, start_col,ins_row, ins_col); //bottom left

				q3(Array, size/2,start_row, start_col + size/2, center_row-1, center_col); // Top Right
			}
		}
		else
		{
			if (ins_row < center_row && ins_col >= center_col) //top right
			{
				if (Array[center_row][center_col] == '-' && Array[center_row][center_col-1] == '-' && Array[center_row-1][center_col-1] == '-')
				{
					Array[center_row][center_col] = start;
					Array[center_row][center_col-1] = start;
					Array[center_row-1][center_col-1] = start;
					start++;



					q3(Array,size/2,start_row ,start_col ,center_row-1,center_col-1); //topleft
					q3(Array,size/2,start_row+size/2, start_col+size/2,center_row, center_col); //bottom right

					q3(Array,size/2,start_row+size/2, start_col , center_row, center_col-1); //bottom left

					q3(Array, size/2,start_row, start_col + size/2, ins_row, ins_col); // Top Right
				}
				
			}
			else
			{
				if (ins_row >= center_row && ins_col >= center_col) //bottom right
					{
						if (Array[center_row-1][center_col-1] == '-' && Array[center_row][center_col-1] == '-' && Array[center_row-1][center_col] == '-')
						{
							Array[center_row-1][center_col] = start;
							Array[center_row][center_col-1] = start;
							Array[center_row-1][center_col-1] = start;
							start++;

							q3(Array,size/2,start_row ,start_col ,center_row-1,center_col-1); //topleft
							q3(Array,size/2,start_row+size/2, start_col+size/2,ins_row, ins_col); //bottom right

							q3(Array,size/2,start_row+size/2, start_col , center_row, center_col-1); //bottom left

							q3(Array, size/2,start_row, start_col + size/2, center_row-1, center_col); // Top Right
						}
						
					}

			}

			

		}
		

	}

}
int main()
{
	cout<<"Enter size of Array"<< endl;
	cin>>n;

	int i,j;
	cout<<"Enter row and column:"<<endl;
	cout<<"Enter row =";
	cin>>i;
	while(i>=n || i<0)
	{
		cout<<"Enter row =";
		cin>>i;

	}

	cout<<"Enter col =";
	cin>>j;
	cout<<endl;
	while(j>=n || j<0)
	{
		cout<<"Enter col =";
		cin>>j;

	}

	char** Array;
	Array = new char* [n];
	for (int i = 0; i < n; ++i)
	{
		Array[i] = new char[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			Array[i][j] = '-';
		}
	}

	Array[i][j] = '0';
	
	q3(Array,n,0,0,i,j);

	for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<Array[i][j]<<" ";
			}
			cout<<endl;
		}
}