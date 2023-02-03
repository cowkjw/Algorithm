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
	vector<int>v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> temp = v;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());


	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(v.begin(), v.end(), temp[i]) - v.begin()<<" ";
	}

	return 0;
}
