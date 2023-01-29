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
	vector<string> v(5);

	int size = 1;
	for (int i = 0; i < 5; i++)
	{
		cin >> v[i];
		size = max(size, (int)v[i].size());
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(v[j].size()<i) continue;
			if (v[j][i] != NULL)
			{
				cout << v[j][i];
			}
		}
	}

	return 0;
}