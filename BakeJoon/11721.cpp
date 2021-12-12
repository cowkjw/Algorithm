#include <iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	int IsTen = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		IsTen++; // 1 2 3 4 5 6 7 8 9 10 
		cout << str[i];
		if (IsTen%10 == 0)
		{
			cout << "\n";
		}

	}

}
