#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int budget;
	cin >> budget;
	int start = 0;
	int end = v.back();
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int tempBudget = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] <= mid)
			{
				tempBudget += v[i];
			}
			else
			{
				tempBudget += mid;
			}
		}
		if (tempBudget > budget)
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