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

	vector<int> v;

	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int ans = 0;
	int left = 0;
	int right = n-1;
	while (left<right)
	{
		if (v[left] + v[right] <= m)
		{
			if (v[left] + v[right] == m)
			{
				right--;
				ans++;
			}
			left++;

		}
		else
		{
			right--;
		}
	}
	cout << ans;

	return 0;
}