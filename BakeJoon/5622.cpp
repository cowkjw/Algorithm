#include <iostream>

using namespace std;

int main()
{
	int N;
	int count = 0;
	string str;
	int alph[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
	
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		N = str[i] - 65;

		count += alph[N];

	}

	cout << count;


}


