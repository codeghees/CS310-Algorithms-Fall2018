#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <iterator> 
#include <queue> 
using namespace std;
int n;
int* RowArray;
int* ColArray;
struct ColS
{
	int ColNo;
	int cap;
};
struct pairs
{
	int row;
	int col;

	
};

/* 
Data structures used = structs and vectors.
Space complexity = O(n^2)
Time complexity = O(n^2)
*/
vector<struct pairs> pc;
ColS* SortedCol;
void fileread(string filename)
{
	ifstream myfile (filename.c_str());
  	string line;
	  if (myfile.is_open())
	  {
	  	myfile>>line;
	  	myfile>>n;

	  	myfile>>line;
	  	//cout<<line<<endl;
	  	RowArray = new int[n];
	  	for (int i = 0; i < n; ++i)
	  	{
	  		int temp;
	  		myfile>>temp;
	  		//cout<<temp<<endl;
	  		RowArray[i] = temp;
	  	}
	  


	  	myfile>>line;
	  	//cout<<line<<endl;
	  	ColArray = new int[n];
	  	for (int i = 0; i < n; ++i)
	  	{
	  		myfile>>ColArray[i];
	  	}
	    myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }


}
void gridprinter(int** Array)
{
	for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		cout<<Array[i][j]<<"\t";
    	}
    	cout<<endl;
    }

}
void sortcol()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (SortedCol[j].cap < SortedCol[j+1].cap)
			{
				ColS temp;
				temp.cap = SortedCol[j].cap;
				temp.ColNo = SortedCol[j].ColNo;

				SortedCol[j].cap = SortedCol[j+1].cap;
				SortedCol[j].ColNo =  SortedCol[j+1].ColNo;
				SortedCol[j+1].cap = temp.cap;
				SortedCol[j+1].ColNo = temp.ColNo;
			}
		}
	}

	// cout<<"Printing Array"<<endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<"Column no is = "<< SortedCol[i].ColNo<< "and cap is = "<< SortedCol[i].cap<<endl;
	// }
}
void q3 (int** Array)
{
	int rowzero = 0;
	int colzero = 0;
	for (int i = 0; i < n; ++i)
	{
		int count = RowArray[i];
		for (int j = 0; j < count; ++j)
		{
			if (SortedCol[j].cap > 0)
			{
				Array[i][SortedCol[j].ColNo] = 1;
				RowArray[i]--;
				
				pairs temp;
				temp.row = i;
				temp.col= SortedCol[j].ColNo;
				pc.push_back(temp);
				
				if (RowArray[i]==0)
				{
					rowzero++;
				}
				SortedCol[j].cap--;
				if (SortedCol[j].cap==0)
				{
					colzero++;
				}
			}
		}
		sortcol();
		
	}
	if ((rowzero==n)&&(colzero==n))
	{
		gridprinter(Array);
		int local = 0;
		for (int i = 0; i < pc.size(); ++i)
		{
			if (local==pc[i].row)
			{
				
				cout<<"("<<pc[i].row<<" , "<<pc[i].col<<") ";
			}
			else
			{
				local++;
				cout<<endl;
			}
		}
	}
	else
	{
		cout<<"Not Possible"<<endl;
		//gridprinter(Array);
	}
}
int main()
{
	string filename;
	cout<<"Enter filename"<<endl;
	cin>>filename;
    fileread(filename);
    int** Array;
    Array = new int* [n];
    for (int i = 0; i < n; ++i)
    {
    	Array[i] = new int[n];
    }
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		Array[i][j] = 0;
    	}
    }
    SortedCol = new ColS[n];
    for (int i = 0; i < n; ++i)
    {
    	SortedCol[i].ColNo = i;
    	SortedCol[i].cap = ColArray[i];
    }
    sortcol();
    //gridprinter(Array);
    q3(Array);
}