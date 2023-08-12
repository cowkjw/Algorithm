#include <iostream>

using namespace std;

int main()
{
	int count[26]{ 0 };

	int Num = 0;
	string S;


	cin >> S;

	for (int i = 0; i <S.length(); i++)
	{
		count[(S[i] - 97)] ++;
	}

	for (int k = 0; k < 26; k++)
	{
		cout << count[k] << " ";
	}


	
}