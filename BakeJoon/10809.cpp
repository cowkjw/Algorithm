#include <iostream>
#include<string.h>
#include<stdbool.h>
using namespace std;

int main()
{
	char S[101];
	bool In = false;
	int j;
	char Alph[27] = "abcdefghijklmnopqrstuvwxyz";

	cin >> S;

	for (int i = 0; i < 26; i++)
	{
		j = 0;
		In = false;


		for (; j < strlen(S); j++)
		{
			if (Alph[i] == S[j])
			{
				In = true;
				break;
			}
		}
		if (In == true)
		{
			cout << j << " ";
		}
		else
		{
			cout << -1 << " ";
		}

	}
	return 0;

}