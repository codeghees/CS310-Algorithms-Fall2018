#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <iterator> 
#include <utility>
using namespace std;
int k;
vector<int> filename(string filename)
{
	std::vector<int> cuts;
	ifstream myfile(filename.c_str());
	string line;
	  if (myfile.is_open())
	  {
	  	myfile>>line;
	 	myfile>>k;
	 	
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
	  return cuts;
}
bool sumDifference(set<int>A, set<int>B)
{
	int sumA =0;
	int sumB = 0;

	for (set<int>:: iterator i = A.begin(); i != A.end(); ++i)
	{
		sumA += *i;
	}

	for (set<int>:: iterator i = B.begin(); i != B.end(); ++i)
	{
		sumB += *i;
	}
	if (sumA-sumB==k)
	{
		return true;
	}
	return false;

}
bool q3(set<int> org, set<int> A, set<int> B,int n)
{

	// cout<< "Recursive"<<endl;
	// cout<<"set a"<<endl;
	// for (set<int>:: iterator i = A.begin(); i != A.end(); ++i)
	// {
	// 	cout<<*i<<" ";
	// }

	// cout<<endl;
	// cout<<"set b"<<endl;
	// for (set<int>:: iterator i = B.begin(); i != B.end(); ++i)
	// {
	// 	cout<<*i<<" ";
	// }
	// cout<<endl;


	// cout<<"set b"<<endl;
	// for (set<int>:: iterator i = B.begin(); i != B.end(); ++i)
	// {
	// 	cout<<*i<<" ";
	// }
	// cout<<endl;

	if (org.size()==0)
	{
		return false;
	}
	set<int> intersect;

    // set_intersection(A.begin(),A.end(),B.begin(),B.end(), std::inserter(intersect,intersect.begin()));
	if (sumDifference(A,B) == true && (A.size()+B.size() == n))
	{
		cout<<"Possible"<<endl;
		cout<<"set a"<<endl;
		int sumA =0,sumB = 0;

		for (set<int>:: iterator i = A.begin(); i != A.end(); ++i)
		{
			sumA+=*i;
			cout<<*i<<" ";
		}

		cout<<endl;

		cout<<"Sum of Set A = "<<sumA<<endl;
		cout<<"set b"<<endl;
		for (set<int>:: iterator i = B.begin(); i != B.end(); ++i)
		{
			sumB+= *i;
			cout<<*i<<" ";
		}
		cout<<endl;
		cout<<"Sum of Set B = "<<sumB<<endl;
		// cout<<endl;
		cout<<"sumDifference = "<< sumA - sumB <<endl;
		return true;
	}
	else
	{
		set<int> A1,B1,A2,B2;
		A1 = A;
		A2 = A;
		B1 = B;
		B2 = B;
		int count = 0;
		int twoEl[2];
		if (org.size()>=1)
		{
			for (set<int>:: iterator i = org.begin(); i!=org.end(); ++i)
			{
				int temp = *i;
				A1.insert(temp);
				B2.insert(temp);
				set<int> t = org;
				t.erase(temp);
				set<int> inter1,inter2;
				bool a,b;
			    set_intersection(A1.begin(),A1.end(),B1.begin(),B1.end(), std::inserter(inter1,inter1.begin()));
				set_intersection(A2.begin(),A2.end(),B2.begin(),B2.end(), std::inserter(inter2,inter2.begin()));
			    
			    if (inter1.size()!=0)
			    {
			    	a = false;
			    }
			    else
			    {
			    	a = q3(t,A1,B1,n);
			    }
			    if (inter2.size()!=0)
			    {
			    	b = false;
			    }
			    else
			    {
			    	b = q3(t,A2,B2,n);
			    }
				bool x = a || b;
				if (x==true)
				{
					return true;
				}
				
			}

			
		}


			
		
	}
	
	return false;

}


int main()
{	
	vector<int> sets = filename("Q3-input-B.txt");
	
	set <int> A;
	set<int> B;
	set<int> org;
	for (int i = 0; i < sets.size(); ++i)
	{
		org.insert(sets[i]);
	}
	if (!(q3(org, A, B, org.size())))
	{

		cout<<"Not Possible"<<endl;
	}
	
	return 0;

}
