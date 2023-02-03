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

	set<string> s;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		s.insert(str);
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (s.find(str) != s.end()) ans++;
	}
	cout << ans;

	return 0;
}
