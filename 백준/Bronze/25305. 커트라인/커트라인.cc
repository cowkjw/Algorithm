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
	int n,k;
	cin >> n>>k;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[n-k];
	return 0;
}
