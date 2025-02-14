#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i * i <= n; i++)
	{
		if (i * i == n)
		{
			cout << 1;
			return 0;
		}
	}


	for (int i = 1; i * i <= n; i++)
	{
		for (int j = 1; j * j <= n; j++)
		{
			if (i * i + j * j == n)
			{
				cout << 2;
				return 0;
			}
		}
	}



	for (int i = 1; i * i <= n; i++)
	{
		for (int j = 1; j * j <= n; j++)
		{
			for (int k = 1; k * k <= n; k++)
			{
				if (i * i + j * j + k * k == n)
				{
					cout << 3;
					return 0;
				}
			}
		}
	}

	cout << 4;
	return 0;
}