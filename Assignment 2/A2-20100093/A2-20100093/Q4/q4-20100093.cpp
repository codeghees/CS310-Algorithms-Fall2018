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
std::vector<double> RackArray;
std::vector<double> P_racks;

struct Prob_Rack
{
	double prob;
	int rack;
	
};

/*	
	Structs and vectors used
	Space complexity = O(n)
	Time complexity = O(n^2)
*/
void sort(Prob_Rack* Array)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (Array[j].prob < Array[j+1].prob)
			{
				Prob_Rack temp;
				temp.prob = Array[j].prob;
				temp.rack = Array[j].rack;

				Array[j].prob = Array[j+1].prob;
				Array[j].rack =  Array[j+1].rack;
				Array[j+1].prob = temp.prob;
				Array[j+1].rack = temp.rack;
			}
		}
	}


	// cout<<"Printing Array"<<endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<"Rack no is = "<< Array[i].rack<< "and prob is = "<< Array[i].prob<<endl;
	// }

}
vector<double> split(string line)
{
	std::vector<double> v;
	string temp ="";
	for (int i = 1; i < line.length(); ++i)
	{
		if (line[i]!=',' && line[i]!=' ' )
		{
			temp = temp + line[i];
		}
		else
		{
			if ((line[i]==',')&&(line[i+1]==' '))
			{
				v.push_back(stod(temp));
				//cout<<temp<<endl;
				temp="";
			}
		}
		if (i+1==line.length())
		{
				v.push_back(stod(temp));
				//cout<<temp<<endl;
				temp="";
			
			
		}

		
	}

	return v;
}
void fileread(string filename)
{
	ifstream myfile (filename.c_str());
  	string line;
	  if (myfile.is_open())
	  {
	  	myfile>>line;
	  	myfile>>n;
		
		myfile>>line;
		getline(myfile,line);
		//cout<<line<<endl;

		RackArray = split(line);
	    
	    myfile>>line;
		getline(myfile,line);
		
		//cout<<line<<endl;
		
		P_racks = split(line);
	    
		//cout<<" "<<P_racks.size()<<endl;

	    myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }
}
void q4(Prob_Rack* Array)
{
	double esttime = 0;
	int localL=0;
	string t = ", ";
	for (int i = 0; i < n; ++i)
	{
		if (i+1==n)
		{
			t = "\n";
		}
		cout<<"Rack"<<Array[i].rack+1<<t;
		localL = localL + RackArray[Array[i].rack];
		esttime = esttime + P_racks[Array[i].rack]*localL;
	}


	cout<<"Expected time = "<< esttime<<endl;
}

int main()
{
	string filename;
	cout<<"Enter filename"<<endl;
	cin>>filename;
	fileread(filename);


	double prob_len[n];
	Prob_Rack* Array = new Prob_Rack[n];
	
	for (int i = 0; i < n; ++i)
	{
		Array[i].prob = P_racks[i]/RackArray[i];
		Array[i].rack = i;
		
	}
	sort(Array);
	q4(Array);
}