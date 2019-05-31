#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <iterator> 
#include <utility>
#include <stdlib.h>     
#include <time.h>       

using namespace std;
/*
 Time Complexity = O(nlog2n).
 Space Complexity = O(n)

 Recurrence Relation:
 T(n) = 2T(n/2) + 2n.
 T(n) = n + n + log(n)	
*/
int genRandomNumber(int m)
{

	int ran = rand() % m;
	return ran;
}
char decode(int pic1, int pic2)
{
	if (pic1==pic2)
	{
		return 'Y';
	}
	else
	{
		return 'N';
	}
}
int q5(int Pictures[],int start, int end)
{
	// cout<<"start = "<<start<<endl;
	// cout<<"end = " << end <<endl;
	// cin>>start;
	if (start<end)
	{
		int mid = start + ((end-start)/2);
		// cout<<"Mid = "<<mid<<endl;  
		
		int firsthalf = q5(Pictures, start , mid);
		int secondhalf = q5(Pictures, mid+1, end);
		int firsthalfc = 0;
		int secondhalfc = 0;
		for (int i = start; i < end; ++i)
		{
			if (decode(firsthalf, Pictures[i]) == 'Y')
			{
				firsthalfc++;
			}

			if (decode(secondhalf, Pictures[i]) == 'Y')
			{
				secondhalfc++;
			}
		}
		if (firsthalfc> secondhalfc)
		{
			return firsthalf;
		}
		else
		{
			return secondhalf;
		}

	}
	else
	{
		if (start==end)
		{
			return Pictures[start];
		}
	}
}
void AuxQ5(int Pictures[],int start, int end)
{
	int maj = q5(Pictures,start,end);
	vector<int> v;
	for (int i = start; i < end; ++i)
	{
		if (decode(maj,Pictures[i]) == 'Y')
		{
			v.push_back(i);
		}
	}
	if (v.size()>end/2)
	{
		cout<<"Success"<<endl;
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"Failure"<<endl;
	}
	

}
int main()
{
	int n;
	cout<<"Enter n = ";
	cin>>n;
	int Pictures[n];
	int m;
	cout<< "Enter m = ";
	cin>>m;
	// n = 15;
	// m = 3;
	// int Pictures[] = {1, 2, 3, 3, 1, 2, 2, 1, 2, 2, 3, 2, 2, 2, 1};
	srand (time(NULL));
	for (int i = 0; i < n; ++i)
	{
		Pictures[i] = genRandomNumber(m);
	}
	// Pictures[] = [1, 2, 3, 3, 1, 2, 2, 1, 2, 2, 3, 2, 2, 2, 1]

	for (int i = 0; i < n; ++i)
	{
		cout<<Pictures[i]<<endl;
	}

	AuxQ5(Pictures,0,n);
	// cout<<q5(Pictures,0,n)<<endl;


}