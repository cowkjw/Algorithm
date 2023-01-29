#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);



	int n;
	cin >> n;

	if (n == 1)
	{
		cout << "*";
		return 0;
	}
	for (int i = 1; i <= n * 2; i++)
	{

		for (int j = 1; j <= n; j++)
		{
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) // 홀수면 짝수에서 짝수면 홀수에서
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}


		cout << '\n';
	}



	return 0;
}