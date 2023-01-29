#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n, x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	auto start = lower_bound(v.begin(), v.end(), x);
	auto end = upper_bound(v.begin(), v.end(), x);

	if (start - end != 0) cout << end - start;
	else cout << -1;
	return 0;
}