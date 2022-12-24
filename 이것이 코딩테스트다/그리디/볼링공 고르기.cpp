#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int ans = 0;
	vector<int> vec(n);

	for (int i = 0; i < vec.size(); i++)
	{
		cin >> vec[i];
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (vec[i] != vec[j])
				ans++;
		}
	}


	cout << ans;

	return 0;
}







