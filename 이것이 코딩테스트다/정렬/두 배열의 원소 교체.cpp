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

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	for (int i = 0; i < m; i++)
	{
		swap(*max_element(b.begin(), b.end()), *min_element(a.begin(), a.end()));
	}

	cout << accumulate(a.begin(), a.end(), 0);
	return 0;
}