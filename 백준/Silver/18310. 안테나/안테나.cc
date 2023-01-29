#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n;
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
	sort(v.begin(), v.end());

	cout << v[(v.size()-1)/2];

	return 0;
}