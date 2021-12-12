#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

	string str;
	 
	string Alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int Overlap[27] = { 0 };
	int max, same = 0;
	int index= 0;


	cin >>str;

	for (int i = 0; i < str.length(); i++)
	{
		
		for (int j = 0; j < 27; j++)
		{
			if ((char)toupper( str[i] )== Alph[j])
			{
				Overlap[j] += 1;

			}
		}
	}

	max = Overlap[0];

	for (int i = 0; i < 27; i++)
	{
		if (Overlap[i] >max)
		{
			max = Overlap[i];
			index = i;
		}
	}
	
	for (int k = 0; k < 27; k++)
	{
		if (Overlap[k] == max)
		{
			same++;
		}
	}


	if (same >= 2) cout << "?";
	else cout << Alph[index];




}