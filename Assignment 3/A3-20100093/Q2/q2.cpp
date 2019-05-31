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
2D Arrays are used
Space Complexity = O(n^2)
Time Complexity = O(n^2)
Team Preference = Last Location
Location Pref =  Team that reaches last on a location
We do GS matching where location makes pair.
*/
int n;
int** teamsPref;
int**locPref;
int entries;
int** statusArray;
struct pairs{
	int Team;
	int Location;
};

vector< struct pairs> PairsFormed;

void parse(string line)
{
	
	if (line[0]=='T')
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
		// cout<<"ROW INDEX = "<<rowindex<<endl;
		temp ="";
		for (int i = counter; i < line.length(); ++i)
		{
			if (line[i]=='L')
			{
				i++;
				while(line[i]!=','&& i != line.length())
				{
					temp = temp + line[i];
					i++;
				}
					
					int col = stoi(temp);
					// cout<<col<<endl;
					for (int i = n-1; i>=0; --i)
					{
						if(teamsPref[rowindex-1][i]==-1)
						{
							teamsPref[rowindex-1][i] = col-1;	
							break;
						}
					}
						
					
					temp= "";
				}
			
		
		}
		temp ="";
		for (int i = 0; i < line.length(); ++i)
		{
			if (line[i]=='L')
			{
				i++;
				while(line[i]!=','&& i != line.length())
				{
					temp = temp + line[i];
					i++;
				}
					
					int col = stoi(temp);
					// cout<<col<<endl;
					for (int i = 0; i<entries; ++i)
					{
						if(statusArray[rowindex-1][i]==-1)
						{
							statusArray[rowindex-1][i] = col-1;	
							break;
						}
					}
						
					
					temp= "";
				}
				if (line[i]=='-')
				{
					for (int i = 0; i<entries; ++i)
					{
						if(statusArray[rowindex-1][i]==-1)
						{
							statusArray[rowindex-1][i] = -2;	
							break;
						}
					}
					
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
	 	teamsPref = new int*[n];
	 	locPref = new int*[n];
	 	for (int i = 0; i < n; ++i)
	 	{
	 		teamsPref[i] = new int[n];
	 		locPref[i] = new int[n];	
	 	
	 	}
	 	for (int i = 0; i < n; ++i)
	 	{
	 		for (int j= 0 ; j < n; ++j)
	 		{
	 			teamsPref[i][j] = -1;
	 			locPref[i][j] = -1;
	 		}
	 	}
	 	entries = 0;
	 	bool check = false;
	 	for (int i = 0; i <= n; ++i)
	 	{
	 		getline(myfile,line);
	 		if ((line.length()>1)&&(check==false))
	 		{
	 			check = true;
	 			for (int j = 0; j < line.length(); ++j)
	 			{
	 				// cout<<j<<endl;
	 				if(line[j]==',')
	 				{
	 					entries++;

	 				}
	 			}
	 			
	 			entries++;
	 			statusArray = new int*[n];
	 			for(int k = 0; k < n; k++ )
	 			{
	 				statusArray[k] = new int[entries];
	 			}
	 			for (int j = 0; j < n; ++j)
	 			{
	 				for (int k = 0; k < entries; ++k)
	 				{
	 					statusArray[j][k] = -1;
	 				}
	 			}

	 		}

	 		parse(line);
	 	}
	 	
		 	// for (int i = 0; i < n; ++i)
		 	// {
		 	// 	for (int j= 0 ; j < n; ++j)
		 	// 	{
		 	// 		cout<<teamsPref[i][j]<<'\t';
		 	// 	}
		 	// 	cout<<endl;
		 	// }
		 	// cout<<endl;
		 	
			for (int i = 0; i < entries; ++i)
			 {
			 	for (int j = 0; j < n; ++j)
			 	{
			 		if (statusArray[j][i]!=-2)
			 		{
			 			int temp =  statusArray[j][i];
			 			for (int k = 0; k < n; ++k)
			 			{
			 				if (locPref[temp][k]==-1)
			 				{
			 					locPref[temp][k] = j;
			 					break;
			 				}
			 			}
			 			
			 		}
			 	}
			 	
			 }
			// for (int i = 0; i < n; ++i)
		 // 	{
		 // 		for (int j= 0 ; j < n; ++j)
		 // 		{
		 // 			cout<<locPref[i][j]<<'\t';
		 // 		}
		 // 		cout<<endl;
		 // 	}
		 // 	cout<<endl; 

		 	
	   	myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }

	  
}
int HighestRankedTeam(int row)
{
	for (int i = n-1; i >= 0; --i)
	{
		if (locPref[row][i]!=-1)
		{
			return locPref[row][i];
		}
	}

	return 0;
}
void updateLocArray(int row, int Location)
{
	for (int i = 0; i < n; ++i)
	{
		if (locPref[row][i]== Location)
		{
			locPref[row][i] = -1;
			
		}
	}

	
}
pairs* FindPair(int Location)
{
	for (int i = 0; i < PairsFormed.size(); ++i)
	{
		if (PairsFormed[i].Team == Location)
		{
			return &PairsFormed[i];
		}
	}

	return NULL;
}

int firstFreeTeam(int* Array)
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
bool PairStable(int currentPair, int ProsPair, int row)
{
	int currentindex,prosindex;

	for (int i = 0; i < n; ++i)
	{
		if(teamsPref[row][i] == currentPair)
		{
			currentindex = i;
		}
		if(teamsPref[row][i] == ProsPair)
		{
			prosindex = i;
		}


	}

	if (currentindex > prosindex)
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
	int freeLocs = n;
	int Teams_free[n];
	int locations_free[n];
	for (int i = 0; i < n; ++i)
	{
		Teams_free[i] = 0;
		locations_free[i] = 0;

	}
	int counter = 0;
	while(freeLocs!=0)
	{	
		int FirstfreeLoc = firstFreeTeam(locations_free); // Free Location

		int RankedTeam = HighestRankedTeam(FirstfreeLoc);
		// cout<<"firstFreeTeam = "<<Freeteam<<endl;
		// cout<<"RankedLocation = "<<RankedLocation<<endl;
		if (Teams_free[RankedTeam]== 0) //if Plane Free
		{
			
				freeLocs--;
				locations_free[FirstfreeLoc] = 1;
				Teams_free[RankedTeam] = 1;

				updateLocArray(FirstfreeLoc,RankedTeam);
				pairs pair;
				pair.Team = RankedTeam;
				pair.Location = FirstfreeLoc;
				PairsFormed.push_back(pair);
				
			
			
		}
		else
		{
			pairs* fpair = FindPair(RankedTeam);
			if (PairStable(fpair->Location, FirstfreeLoc, RankedTeam) == false)
			{
				int FreedLoc = fpair->Location;
				fpair->Location = FirstfreeLoc;
				locations_free[FirstfreeLoc] = 1;
				locations_free[FreedLoc] = 0;
				// freeAirPorts++;
				
			}
			else
			{
				updateLocArray(FirstfreeLoc,RankedTeam);
				

				
			}


		}



	}
	cout<<"Final Destinations:"; 	
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
		cout<<"L"<<PairsFormed[i].Location+1<<" "<<"T"<<PairsFormed[i].Team+1<<temp;
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