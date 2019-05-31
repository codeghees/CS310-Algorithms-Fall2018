#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <iterator> 
using namespace std;

int TotalFuel;
int Rate;
int TimetoFill;
int nStops;
int* StopArray;
int TotalDistance;

int splitfunction(string line)
{
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i]==' ')
		{
			string temp = "";
			for (int j = i+1 ; j < line.length(); ++j)
			{
				temp = temp + line[j];
				
			}
			return stoi(temp);
		}
	}
}
void fileread(string filename)
{
	
	ifstream myfile (filename.c_str());
  	string line;
	  if (myfile.is_open())
	  {
	  	myfile>>line;
	  	myfile>>TotalFuel;

	  	myfile>>line;
	  	myfile>>Rate;


	  	myfile>>line;
	  	myfile>>TimetoFill;


	  	myfile>>line;
	  	myfile>>nStops;
	 
	  	StopArray = new int[nStops+1];

	  	for (int i = 0; i < nStops+1; ++i)
	  	{

	  		getline(myfile,line);
	  		if (line.length() == 0)
	  		{
	  			getline(myfile,line);
	  		}
	  		StopArray[i] = splitfunction(line);
	  	}
		TotalDistance = StopArray[nStops];
	  	
	    
	    myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }


}
void q2()
{
	double DistTrav = 0;
	double PetrolLevel = TotalFuel;
	int curr_stop = 0;
	double temp_p = 0;
	double time = 0;

	while(DistTrav!=TotalDistance)
	{
		
		temp_p = Rate * (StopArray[curr_stop] - DistTrav);

		

		if (temp_p<=PetrolLevel)
		{
			PetrolLevel = PetrolLevel - temp_p;
			DistTrav = StopArray[curr_stop];
			curr_stop++;

		}
		else
		{
			cout<<"L"<<curr_stop<<" "<<((temp_p - PetrolLevel)/TimetoFill)<<endl;
			time = time + ((temp_p - PetrolLevel)/TimetoFill);
			PetrolLevel = 0;
			DistTrav = StopArray[curr_stop];
			curr_stop++;

		}
	}
	// PetrolLevel = PetrolLevel - (StopArray[0] * Rate);

	// DistTrav = StopArray[0];
	// curr_stop = 1;
	// for (int i = 1; i < nStops; ++i)
	// {
	// 	cout<<StopArray[i] << " PETROL LEVEL " << PetrolLevel<<endl;

	// 	temp_p = (StopArray[i] - StopArray[i-1]) * Rate; // Petrol needed for next stop
		
	// 	if (temp_p <= PetrolLevel)
	// 	{	
	// 		curr_stop++;
	// 		PetrolLevel = PetrolLevel - temp_p;
	// 		DistTrav = StopArray[i-1];
			
			
	// 	}
	// 	else
	// 	{
			
	// 		time = time + ((temp_p - PetrolLevel) / TimetoFill); 
	// 		cout<<"Refueling"<<endl;
	// 		cout<<"L"<<i<<" "<<((temp_p - PetrolLevel) / TimetoFill)<<endl;
	// 		PetrolLevel = temp_p;
		
	// 		DistTrav = StopArray[i-1];
	// 		curr_stop++;
		

	// 	}
	// 	if(i+1==nStops)
	// 	{
			
	// 			if (temp_p <= PetrolLevel)
	// 			{	
					
	// 				PetrolLevel = PetrolLevel - temp_p;
	// 				DistTrav = StopArray[i];
	// 				break;
					
	// 			}
	// 			else
	// 			{
					
	// 				time = time + ((temp_p - PetrolLevel) / TimetoFill); 
	// 				cout<<"Refueling"<<endl;
	// 				cout<<"L"<<i<<" "<<((temp_p - PetrolLevel) / TimetoFill)<<endl;
	// 				PetrolLevel = temp_p;
				
	// 				DistTrav = StopArray[i];
					
	// 				break;

	// 			}

	// 	}
		
	// }
	

	// if (curr_stop==nStops)
	// {
		
	// 		temp_p = (TotalDistance - DistTrav) * Rate;
	// 		if (temp_p <= PetrolLevel)
	// 		{
	// 			curr_stop++;
	// 			PetrolLevel = PetrolLevel - temp_p;
	// 			DistTrav = TotalDistance ;
				
				
	// 		}
	// 		else
	// 		{
	// 			time = time + ((temp_p) / TimetoFill); 
	// 			cout<<"L"<<nStops<<" "<<((temp_p ) / TimetoFill)<<endl;
	// 			PetrolLevel = PetrolLevel + (temp_p - PetrolLevel);
				
	// 			DistTrav = TotalDistance;
	// 			curr_stop++;
				

	// 		}
		
		
	// }
	if (DistTrav==TotalDistance)
	{
		cout<<"Time taken = "<<time<< endl;
	}
	
}

int main()
{
	string filename;
	cout<<"Enter name of File"<<endl;
	cin>>filename;
	fileread(filename);
	// cout<<TotalFuel<<endl;
	// cout<<TotalDistance<<endl;
	// for (int i = 0; i < nStops+1; ++i)
	// {
	// 	cout<<StopArray[i]<<endl;
	// }
	
	q2();

}