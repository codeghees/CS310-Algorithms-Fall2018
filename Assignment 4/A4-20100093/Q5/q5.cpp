#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <iterator> 
#include <utility>
#include<bits/stdc++.h> 
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <unistd.h>
using namespace std;
/*
 Time Complexity = N^3
 Space Complexity = N^2

 Used int arrays
*/
	

int  c1, c2;
int r1, r2;
int n;
// std::vector<int> same;
bool check(int r)
{
	for (int i = 0; i < same.size(); ++i)
	{
		if (same[i]==r)
		{
			return true;
		}
	}
	return false;
}
int randomgen()
{
	
	int random = rand() % 10000 - 3000;

	// while(check(random)!=false)
	// {
	// 	random = rand() % 10000 - 6000;
	

	// }
		same.push_back(random);
	return random ;
}
int** filename(string filename)
{
	vector<int> v;
	ifstream myfile(filename.c_str());
	string line;
	  if (myfile.is_open())
	  {
	  	myfile>>line;
	 	myfile>>n;
	 	
	 	int** Array = new int* [n];
	 	for (int i = 0; i < n; ++i)
	 	{
	 		Array[i] = new int[n];
	 	}
	 	while(!myfile.eof())
	 	{
	 		getline(myfile,line);
	 		// cout<<line<<endl;
	 		string x = "";
	 		for (int i = 0; i < line.length(); ++i)
	 		{
	 			if (line[i] != ' ' && line[i] != ',' && line[i] != '{' && line[i] != '}' )
	 			{
	 				x = x + line[i];
	 			}
	 			else
	 			{
	 				if (line[i] == ',' || line[i] == '}')
	 				{
	 					int temp = stoi(x);
	 					x = "";
	 					v.push_back(temp);
	 				}
	 			}
	 			
	 		}
	 		

	 	}
	 	// for (int i = 0; i < v.size(); ++i)
	 	// {
	 	// 	cout<<v[i]<<endl;
	 	// }

	 	int count = 0;
	 	for (int i = 0; i < n; ++i)
	 	{
	 		for (int j = 0; j < n; ++j)
	 		{
	 			Array[i][j] = v[count++];
	 		}
	 	}
	 	return Array;
	   	myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }
	  int** A;
	  return A;
}

int maxSum1D(int Array[], int s, int e)
{
	int globalMax = Array[s];
	int localMax = Array[s];
	for (int i = s; i <= e; ++i)
	{
		if (Array[i] > localMax + Array[i])
		{
			localMax = Array[i];
			c1 = i;
		}
		else
		{
			localMax = Array[i] + localMax;
		}

		if (localMax > globalMax)
		{
			globalMax = localMax;
			c2 =i;
		}
		
	}
	return globalMax;
}

void q5(int** Array, int n)
{
	int maxSum = INT_MIN;
	int localMax;
	int dp[n][n];
	int col1,col2;
	int up,left,diagonal;
	

	int row, col, size;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i-1<0)
			{
				up =0;
			}
			else
			{
				up = dp[i-1][j];
			}
			if (j-1<0)
			{
				left = 0;
			}
			else
			{
				left = dp[i][j-1];
			}
			if (i-1<0 || j-1<0)
			{
				diagonal = 0;
			}
			else
			{
				diagonal = dp[i-1][j-1];
			}
			
			dp[i][j] = Array[i][j] +  up + left - diagonal;
			}
	}

	for (int k = 1; k < n; ++k)
	{
		// maxSum = INT_MIN;
		for (int i = k-1; i < n; ++i)
		{
			for (int j = k-1; j < n; ++j)
			{
					if (i-k<0)
					{
						up =0;
					}
					else
					{
						up = dp[i-k][j];
					}
					if (j-k<0)
					{
						left = 0;
					}
					else
					{
						left = dp[i][j-k];
					}
					if (i-k<0 || j-k<0)
					{
						diagonal = 0;
					}
					else
					{
						diagonal = dp[i-k][j-k];
					}

					localMax = dp[i][j]-  up - left + diagonal;
					if (localMax > maxSum)
					{
						maxSum = localMax;
						row = i;
						col = j;
						size = k;

					}
						
			}
		}
	
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// cout<<Array[i][j]<<" ";
		}
		// cout<<endl;
	}
	// cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	cout<<"MAX SUM =" <<maxSum<<endl;
	cout<<"Top left "<<row-(size-1)<< ", "<<col-(size-1)<<endl;
	cout<<"Bottom Right "<<row<< ", "<<col<<endl;
	cout<<"Width = " <<size<<endl;
}

int main()
{

	srand(time(NULL));
	cout<<"Press 1 for file read, 2 for random Array"<<endl;
	int op;
	cin>>op;
	if (op==1)
	{
			cout<<"Enter filename"<<endl;
			string filenam;
			cin>>filenam;
			int** Array = filename(filenam);
			for (int i = 0; i < n; ++i)
		 	{
		 		for (int j = 0; j < n; ++j)
		 		{
		 			cout<<Array[i][j]<<" ";
		 		}
		 		cout<<endl;
		 	}
		 	q5(Array,n);

		
	}
	else
	{
		if (op == 2)
		{
			cout<<"Enter size of Array "<<endl;
			cin>>n;
			int** Array = new int* [n];
		 	for (int i = 0; i < n; ++i)
		 	{
		 		Array[i] = new int[n];
		 	}
		 	for (int i = 0; i < n; ++i)
		 	{
		 		for (int j = 0; j < n; ++j)
		 		{
		 			Array[i][j] = randomgen();
		 		}
		 	}
		 		for (int i = 0; i < n; ++i)
		 	{
		 		for (int j = 0; j < n; ++j)
		 		{
		 			cout<<Array[i][j]<<" ";
		 		}
		 		cout<<endl;
		 	}
		 	q5(Array,n);


		}
	}

	// return 0;
// 	int Array[][8] = { {13, -3, 11, 18, -41, -75, -20, 25},
// {11, -29, -15, 14, 17, 6, 4, 13},
// {-93, -31, -10, 2, 23, -7, 27, 21}, 
// {2, -9, -25, 41, 67, 44, 14, -13}, 
// {14, -12, 10, 31, 13, 51, 14, 5}, 
// {4, 4, -25, 4, 67, 13, 21, -19},
// {22, -77, -15, 53, 37, 47, 41, 13},
// {-76, 45, 11, -27, 8, 6, 7, 32}};
// 	int check[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
// 	// maxSum1D(check, 0 , 7);
// 	// cout<<c1<<endl;
// 	// cout<<c2<<endl;
	// q5(Array,n);

	return 0;
}

/*
for (int i = 0; i < n; ++i)
	{
		for (int m = 0; m < n; ++m)
		{
			colsums[m] = 0;
		}
		for (int j = i; j < n; ++j)
		{

			for (int k = 0; k < n; ++k)
			{
				colsums[k] += Array[k][j];

				
			}
		
		localMax = maxSum1D(colsums,0,n-1);
		if (localMax> maxSum)
		{

			cout<<endl;
			// if(i-j == c1-c2)
			// {
				maxSum = localMax;
				r1 = i; // top
				r2 = j; // bottom
				col1 = c1; // left most
				col2 = c2; // right most

			cout<<r1<<" "<<c1<<endl;
			cout<<r2<<" "<<c2<<endl;

			// }
		}	
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<Array[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for (int i = r1; i <= r2; ++i)
	{
		for (int j = c1; j <= c2; ++j)
		{
			cout<<Array[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
			cout<<r1<<" "<<c1<<endl;
			cout<<r2<<" "<<c2<<endl;
			cout<<endl;


	cout<< maxSum<<endl; 
*/