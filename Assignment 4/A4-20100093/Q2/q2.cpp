#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <iterator> 
#include <utility>
using namespace std;
int n;
std::vector<int> cuts;
int** memo;
std::vector< vector<int> > path;
std::vector<int> pt;

/*
Q2(cuts, start,end) = if start>= end return 0
Q2(cuts, start,end) = Min (start - end + Q2(cuts, start,cut) + Q2(cuts, cut, end))  [Usin a for loop for m cuts]

cuts =  array of cuts

Time Complex = O(n^2)
Maximum subproblems = N^N


*/

void filename(string filename)
{

	ifstream myfile(filename.c_str());
	string line;
	  if (myfile.is_open())
	  {
	  	myfile>>line;
	 	myfile>>n;
	 	
	 	myfile>>line;

	 	while(!myfile.eof())
	 	{
	 		int temp;
	 		myfile>>temp;
	 		cuts.push_back(temp);
	 		

	 	}
	 	cuts.pop_back();
	 	for (int i = 0; i < cuts.size(); ++i)
	 	{
	 		// cout<<cuts[i]<<endl;
	 	}

	   	myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }
}

int min(int a , int b)
{
	if (a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int q2(vector<int> cut, int start, int end)
{
	if (start>=end)
	{
		return 0;
	}
	if (memo[start][end-1]!=-1)
	{
		// cout<<"HIT"<<endl;
		return memo[start][end-1];
	}

	int min = 999999;
	bool check = false;
	int first, second, cost = 0;
	for (int i = 0; i < cut.size(); ++i)
	{
		if (cut[i] > start && cut[i]< end)
		{
			 first = q2(cut, start, cut[i]);
			 second = q2(cut, cut[i], end);
			 check = true;
		}
		if (check == true)
		{
			cost = first + second + (end - start);
			if(cost < min)
			{
				min =  cost;
			}

		}

		
		
	}
	if (check==false)
	{
		return 0;
	}
	memo[start][end-1] = min;
	return min;




}
int q2v(vector<int> cut, int start, int end, vector<int>& p)
{
	if (start>=end)
	{
		return 0;
	}
	if (memo[start][end-1]!=-1)
	{
		// cout<<"HIT"<<endl;
		return memo[start][end-1];
	}

	int min = 999999;
	bool check = false;
	int first, second, cost = 0;
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < cut.size(); ++i)
	{
		if (cut[i] > start && cut[i]< end)
		{
			 first = q2v(cut, start, cut[i], A);
			 second = q2v(cut, cut[i], end, B);
			 check = true;
					
			if (check == true)
			{
				cost = first + second + (end - start);
			
				if(cost < min)
				{	
					p.push_back(cut[i]);
					min =  cost;
					for (int j = 0; j < A.size(); ++j)
					{
						
						p.push_back(A[j]);
					}

					for (int k = 0; k < B.size(); ++k)
					{
						
						p.push_back(B[k]);
					}

				}


			}
		}

		
		
	}
	if (check==false)
	{
		return 0;
	}
	memo[start][end-1] = min;
	pt = p;
	return min;




}
int main()
{
	string file;
	cin>>file;
	filename(file);
	memo = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		memo[i] = new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <  n; ++j)
		{
			memo[i][j] = -1;
		}
	}
	std::vector<int> v;
	cout<<q2v(cuts,0, n,v )<<endl;
	// for (int i = 0; i < pt.size(); ++i)
	// {
	// 	cout<< pt[i]<<" ";
	// }
	cout<<endl;
	// for (int i = 0; i < path.size(); ++i)
	// {
	// 	for (int j = 0; j < path[i].size(); ++j)
	// 	{
	// 		cout<< path[i][j]<<" ";
	// 	}
	// cout<<endl;	
	// }

}