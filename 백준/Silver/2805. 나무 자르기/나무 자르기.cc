#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int start = 0;
	int end = *max_element(v.begin(), v.end());
	int ans = 0;
	while (start <= end)
	{
		long long sum = 0;

		int mid = (start + end) / 2;
		for (const auto& item : v)
		{
			if (item > mid)
			{
				sum += item - mid;
			}
		}

		if (m > sum)
		{
			end = mid - 1;
		}
		else
		{
			ans = mid;
			start = mid + 1;
		}

	}
	cout << ans;
	
	return 0;
}