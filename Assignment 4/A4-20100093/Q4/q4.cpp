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

T(a,b,c) = {if a[i] == c[i] : T(a[1:],b,c[1:]) else if b[i] == c[i] : T(a,b[1:],c[1:]) else if a[i] == b[i] == c[i] : T(a[1:],b,c[1:])||T(a,b[1:],c[1:])
a b c are strings.
Time Complex = O(LenA*LenB)
SubProblems 2^min(lenA,lenB) 
*/
int n;
vector<string> filename(string filename)
{

	ifstream myfile(filename.c_str());
	string line;
	  if (myfile.is_open())
	  {
	  	std::vector<string> v;
	  	for (int i = 0; i < 3; ++i)
	  	{
	  		string temp;
	  		getline(myfile,temp);
	  		v.push_back(temp);
	  	}
		return v;
	   	myfile.close();
	  }

	  else
	  {
	  	cout << "Unable to open file"; 
	  	
	  }
	  std::vector<string> v;
	  return v;
}

bool q4(string a, string b, string c, bool**& Array)
{
	int lenA = a.length();
	int lenB = b.length();
	if (c.length()!= lenA+lenB)
	{
		cout<<lenA<<endl;
		cout<<lenB<<endl;
		cout<<c.length()<<endl;

		return false;
	}
	Array[0][0] = true;

	for (int i = 1; i <= lenA; ++i)
	{
		if (a[i-1] == c[i-1])
		{
			Array[i][0] = Array[i-1][0];
			
		}
	}

	for (int i = 1; i <= lenB; ++i)
	{
		if (b[i-1] == c[i-1])
		{
			Array[0][i] = Array[0][i-1];
		}
	}

	for (int i = 1; i <= lenA; ++i)
	{
		for (int j = 1; j <= lenB; ++j)
		{
			if (a[i-1] == c[i+j-1] && b[j-1] != c[i+j-1])
			{
				Array[i][j] = Array[i-1][j];
			}

			if (a[i-1] != c[i+j-1] && b[j-1] == c[i+j-1])
			{
				Array[i][j] = Array[i][j-1];
			}


			if (a[i-1] == c[i+j-1] && b[j-1] == c[i+j-1])
			{
				Array[i][j] = Array[i-1][j] || Array[i][j-1];
			}
		}

	}


	// for (int i = 1; i <= lenA; ++i)
	// {
	// 	for (int j = 1; j <= lenB; ++j)
	// 	{
	// 		cout<< Array[i][j]<<" ";
	// 	}
	// 	cout <<endl;

	// }


	if (Array[lenA][lenB]==0)
	{
		cout<<"Not Possible"<<endl;
		return 0;
	}
	else
	{
		cout<<"Possible"<<endl;
	}


	int i=1;
	int j=0;
	string x = "";
	bool cd= true;
	cout << "S1";
	for(int x = 0; x <= c.length();x++)
	{
		if(i < lenA && cd == true)
		{
			cout << a[i-1];
			if(Array[i+1][j]==1)
			{
				i++;
			}
			else 
			if(Array[i][j+1]==1)
			{
				j++;
				cout << " S2 ";
				cd = false;
			}
		}
		else if(j < lenB && cd == false)
		{
			cout << b[j-1];
			if(Array[i][j+1]==1)
			{
				j++;
			}
			else if(Array[i+1][j]==1)
			{
				i++;
				cout << " S1 ";
				cd = true;
			}
		}

	}
	cout<<endl;
	
	// while(i+j <= c.length())
	// {

	// 		if (i+1<=lenA )
	// 		{

	// 			if(Array[i+1][j] == 1 && c[i+j+1] == a[i+1] )
	// 			{
	// 				i++;
	// 				x = x + a[i];
	// 				if (cd==false)
	// 				{
						
	// 				}
	// 				else
	// 				{
	// 					cd = false;
	// 					x ="";

	// 				}
					
	// 			}


			
	// 		}
	// 		else
	// 		{
	// 			if (j+1<= lenB)
	// 			{
					
				
	// 				if (Array[i][j+1] == 1 && c[i+j+1] == b[j+1] )
	// 				{
	// 					j++;
	// 					x = x + b[i];
	// 					if (cd==true)
	// 					{
	// 						/* code */
	// 					}
	// 					else
	// 					{
	// 						cd = true;
	// 						x ="";
	// 					}
	// 					// c = true;
	// 				}
	// 			}

	// 		}

	// 		if (cd==false)
	// 		{
	// 			cout<<"S1"<<x<<endl;

	// 		}

	// 		if (cd==true)
	// 		{
	// 			cout<<"S2"<<x<<endl;
	// 		}
		

	// }




	return Array[lenA][lenB];
}	


int main()
{
	string filenam;
	cin>>filenam;
	vector<string> words = filename(filenam);
	for (int i = 0; i < words.size(); ++i)
	{
		cout<<words[i]<<endl;
	}
	bool** Array;
	Array= new bool*[words[0].length()+1];
	for (int i = 0; i < words[0].length()+1; ++i)
	{
		Array[i] = new bool[words[1].length()+1];
	}


	for (int i = 0; i < words[0].length()+1; ++i)
	{
		for (int j = 0; j < words[1].length()+1; ++j)
		{
			Array[i][j] = false;
		}
	}

	q4(words[0],words[1],words[2], Array);
	cout<<"X"<<endl;
	return 0;
}