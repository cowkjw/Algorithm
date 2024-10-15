#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;

		for (int j = 2; j < 1000001; j++)
		{
			if (num%j ==0 )
			{
				cout << "NO\n";
				break;
				
			}
			if (j == 1000000)
			{
				cout << "YES\n";
			}
		}
		
	}

	return 0;
}