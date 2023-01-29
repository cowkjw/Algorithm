#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cin >> m;
	vector<int> v2(m);

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		cin >> v2[i];
	}
	for (const auto& item : v2)
	{
		if (binary_search(v.begin(), v.end(), item)) cout << "yes ";
		else cout << "no ";
	}
	return 0;
}