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

	map<string, int> m;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		m[str]++;
	}

	cout << (*max_element(m.begin(), m.end(), [](const pair<string, int>& a, const pair<string, int>& b)
		{
			return a.second < b.second;
		})).first;

	return 0;
}