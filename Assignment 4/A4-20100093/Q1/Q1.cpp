#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <iterator> 
#include <utility>
using namespace std;
int* Status;
int* Memo;
int n;
int* HCap;
int* LCap;

/*
func(1) = H[i]>L[i]: return H[i] :L[i]
func(n) = max(L[i]+func(n-1),H[i]+func(n-2))
L and H represent arrays of low and high workload
Time Complexity = O(2 * No of Weeks)

 */

void filename(string filename, int& n, int*& HCap, int*& LCap)
{

	ifstream myfile(filename.c_str());
	string line;
	  if (myfile.is_open())
	  {
	  	myfile>>line;
	 	myfile>>n;
	 	HCap = new int[n];
	 	LCap = new int [n];

	 	myfile>>line;
	 	for (int i = 0; i < n; ++i)
	 	{
	 		int temp;
	 		myfile>>temp;
	 		HCap[i] = temp;
	 	}


	 	myfile>>line;
	 	for (int i = 0; i < n; ++i)
	 	{
	 		int temp;
	 		myfile>>temp;
	 		LCap[i] = temp;
	 	}

	   	myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }
}
int max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int q1(int i)
{
	// cout<<"Called = "<<i<<endl;
	if (i>0)
	{
		
		if (i==n)
		{
			int HW = HCap[i-1] + q1(i-2);
			int LW = LCap[i-1] + q1(i-1);
			
			int mx =  max(HW,LW);
			if (mx==HW)
			{
				Status[i-1] = 1;
				
			}
			else
			{
				Status[i-1] = -1;
			}
			Memo[i-1] = mx;
			return mx;

		}
		if (Memo[i-1]!= -1)
		{
			return Memo[i-1];
		}
		int HW = HCap[i-1] + q1(i-2);
		int LW = LCap[i-1] + q1(i-1);
		
		int mx =  max(HW,LW);
		if (mx==HW)
		{

			Status[i-1] = 1;
			
		}
		else
		{
			
			Status[i-1] = -1;
		}

		Memo[i-1] = mx;
		return mx;

	
	}
		
	else
	{
		if (i<=0)
		{
			return 0;
		
		}


	}

	return 0;	

}
int main()
{

	string file;
	cin>>file;
	filename(file, n, HCap, LCap);
	Status = new int[n];
	Memo = new int[n];
	for (int i = 0; i < n; ++i)
	{
		Status[i] = 0;
		Memo[i] = -1;
	}


	cout<<"Total Revenue = "<<q1(n)<<endl;
	for (int i = n-1; i>=0; --i)
	{
		if (Status[i] == 1)
		{
			if (i-1>=0)
			{
				Status[i-1] = 0;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (Status[i]==1)
		{
			cout<<"Week "<<i+1<<": "<<"High "<<HCap[i]<<endl;
		}
		if (Status[i]==-1)
		{
			cout<<"Week "<<i+1<<": "<<"Low "<<LCap[i]<<endl;
		}
		if (Status[i]==0)
		{
			cout<<"Week "<<i+1<<": "<<"Priming"<<endl;
						
		}
	}


}