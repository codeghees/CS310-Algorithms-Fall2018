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
It runs the standard GS matching algorithm and terminates when no AirPort is left
Space Complexity = O(n*n)
Time Complexity = O(n*n)

*/
int n;
int** AirPlane;
int** AirPort;
struct pairs{
	int AirPort;
	int AirPlane;
};

vector< struct pairs> X;
vector< struct pairs> PairsFormed;

void insertInArray(int**Array, int row, int insert)
{
	for (int i = 0; i < n; ++i)
	{
		if (Array[row-1][i] == -1 )
		{
			Array[row-1][i] = insert-1;
			return;
		}
	}
}

void parse(string line)
{
	if (line[0]=='P')
	{
		int counter = 1;
		int rowindex;
		string temp ="";
		while(line[counter]!= ':')
		{
			temp = temp + line[counter];
			counter++;


		}
		rowindex =  stoi(temp);
		//cout<<"ROW INDEX = "<<rowindex<<endl;
		temp ="";
		for (int i = counter+1; i < line.length(); ++i)
		{
			if (line[i]=='A')
			{
				i++;
				while(line[i]!=','&& i != line.length())
				{
					temp = temp + line[i];
					i++;
				}
				if(line[i]==',' || i == line.length())
				{
					
					
					int col = stoi(temp);
					//cout<<col<<endl;
					insertInArray(AirPlane,rowindex,col);
					temp= "";

				}
				
				
			}
			
		
		}
			
		
		
	}

	if (line[0]=='A')
	{
		int counter = 1;
		int rowindex;
		string temp ="";
		while(line[counter]!= ':')
		{
			temp = temp + line[counter];
			counter++;


		}
		rowindex =  stoi(temp);
		//cout<<"ROW INDEX = "<<rowindex<<endl;
		temp ="";
		for (int i = counter+1; i < line.length(); ++i)
		{
			if (line[i]=='P')
			{
				i++;
				while(line[i]!=','&& i != line.length())
				{
					temp = temp + line[i];
					i++;
				}
				if(line[i]==',' || i == line.length())
				{
					
					
					int col = stoi(temp);
					//cout<<col<<endl;
					insertInArray(AirPort,rowindex,col);
					temp= "";

				}
				
				
			}
			
		
		}
			
		
	}
}
void parsePairs(string line)
{
	// cout<<line<<endl; 
	int AirPlane;
	int AirPort;
	for (int i = 0; i < line.length(); ++i)
	{
		string temp = "";
		if (line[i] == 'P')
		{
			++i;
			while(line[i] != ' ')
			{
				temp = temp + line[i];
				i++;

			}
			
			AirPlane = stoi(temp);
		}
		temp = "";
		if (line[i]=='A')
		{
			i++;
			while(i!=line.length())
			{
				temp = temp + line[i];
				i++;


			}
			

			AirPort = stoi(temp);
		}
	}
	pairs temp;
	temp.AirPlane = AirPlane;
	temp.AirPort = AirPort;

	X.push_back(temp);
	// cout<<"AirPlane = "<<AirPlane<<endl;
	// cout<<"AirPort = "<<AirPort<<endl;
}

void DealWithLineX(string line)
{
	if (line[0]=='X')
	{

		for (int i = 1; i < line.length(); ++i)
		{
			string temp = "";
			if (line[i]=='P')
			{
				int counter = i;
				while(line[counter]!= ',' && counter != line.length())
				{
					temp = temp + line[counter];
					counter++;

				}
				parsePairs(temp);
				i = counter;
			}
			

		}
		
	}

}
void fileread(string filename)
{
	ifstream myfile(filename.c_str());
	string line;
	  if (myfile.is_open())
	  {
	  	myfile>>line;
	 	myfile>>n;
	 	AirPort = new int*[n];
	 	AirPlane = new int*[n];

	 	for (int i = 0; i < n; ++i)
	 	{
	 		AirPlane[i] = new int[n];
	 		AirPort[i] = new int[n];
	 	}
	 	for (int i = 0; i < n; ++i)
	 	{
	 		for (int j = 0; j < n; ++j)
	 		{
	 			AirPlane[i][j] = -1;
	 			AirPort[i][j] = -1;
	 		}
	 	
	 	}
	 	getline(myfile,line);
	 	while(line[0]!='X')
	 	{
	 		
		   	parse(line);
		   	
		   	getline(myfile,line);

	 	}
	 	DealWithLineX(line);
	 	// cout<<"AirPlane Array"<<endl;
	 	for (int i = 0; i < n; ++i)
	 	{
	 		for (int j = 0; j < n; ++j)
	 		{
	 			// cout<<AirPlane[i][j];
	 		}
	 		// cout<<endl;
	 	}
	 	// cout<<"AirPort Array"<<endl;
	 	for (int i = 0; i < n; ++i)
	 	{
	 		for (int j = 0; j < n; ++j)
	 		{
	 			// cout<<AirPort[i][j];
	 		}
	 		// cout<<endl;
	 	}

	 	for (int i = 0; i < X.size(); ++i)
	 	{
	 		// cout<<"AirPlane = "<< X[i].AirPlane<<endl;
	 		// cout<<"AirPort = "<< X[i].AirPort<<endl;
	 	}
	   	myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }
}
int firstFreeAirPort(int* Array)
{
	for (int i = 0; i < n; ++i)
	{
		if (Array[i]==0)
		{
			return i;
		}
	}

	return 0;
}
int HighestRankedPlane(int row)
{
	for (int i = 0; i < n; ++i)
	{
		if (AirPort[row][i]!=-1)
		{
			return AirPort[row][i];
		}
	}

	return 0;
}
void updateAirPlaneArray(int row, int plane)
{
	for (int i = 0; i < n; ++i)
	{
		if (AirPort[row][i]== plane)
		{
			AirPort[row][i] = -1;
			
		}
	}

	
}


int FindinX(int AirPort, int AirPlane)
{
	for (int i = 0; i < X.size(); ++i)
 	{
 		if (X[i].AirPlane == AirPlane && X[i].AirPort == AirPort)
 		{
 			return 0;
 		}
	}

 	return 1;


}
pairs* FindPair(int plane)
{
	for (int i = 0; i < PairsFormed.size(); ++i)
	{
		if (PairsFormed[i].AirPlane == plane)
		{
			return &PairsFormed[i];
		}
	}

	return NULL;
}

bool PairStable(int currentPair, int ProsPair, int row)
{
	int currentindex,prosindex;

	for (int i = 0; i < n; ++i)
	{
		if(AirPlane[row][i] == currentPair)
		{
			currentindex = i;
		}
		if(AirPlane[row][i] == ProsPair)
		{
			prosindex = i;
		}


	}

	if (currentindex < prosindex)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void stablematch()
{
	int freeAirPorts = n;
	int AirPort_free[n];
	int AirPlane_free[n];
	for (int i = 0; i < n; ++i)
	{
		AirPort_free[i] = 0;
		AirPlane_free[i] = 0;

	}
	int counter = 0;
	while(freeAirPorts!=0)
	{	
		int FreeAirPort = firstFreeAirPort(AirPort_free);

		int RankedPlane = HighestRankedPlane(FreeAirPort);

		if (AirPlane_free[RankedPlane]== 0) //if Plane Free
		{
			if (FindinX(FreeAirPort,RankedPlane)==1) // If Allowed in X
			{
				freeAirPorts--;
				AirPlane_free[RankedPlane] = 1;
				AirPort_free[FreeAirPort] = 1;
				updateAirPlaneArray(FreeAirPort,RankedPlane);

				pairs pair;
				pair.AirPort = FreeAirPort;
				pair.AirPlane = RankedPlane;
				PairsFormed.push_back(pair);
				
			}
			else
			{
				updateAirPlaneArray(FreeAirPort,RankedPlane);


			}
			
		}
		else
		{
			pairs* fpair = FindPair(RankedPlane);
			if (PairStable(fpair->AirPort, FreeAirPort, RankedPlane) == false && FindinX(FreeAirPort,RankedPlane) == 1)
			{
				int FreedAirPort = fpair->AirPort;
				fpair->AirPort = FreeAirPort;
				AirPort_free[FreeAirPort] = 1;
				AirPort_free[FreedAirPort] = 0;
				// freeAirPorts++;
				
			}
			else
			{
				updateAirPlaneArray(FreeAirPort,RankedPlane);

			}


		}



	}
	cout<<"Stable Matching:"; 	
	for (int i = 0; i < PairsFormed.size(); ++i)
	{
		string temp;
		if (i == PairsFormed.size()-1)
		{
			temp = "";
		}
		else
		{
			temp =", ";
		}
		cout<<"A"<<PairsFormed[i].AirPort+1<<" "<<"P"<<PairsFormed[i].AirPlane+1<<temp;
	}

	cout<<endl;
}
int main()
{
	string filename;
	cout<<"Enter filename = ";
	cin>>filename;
	fileread(filename);
	stablematch();



}