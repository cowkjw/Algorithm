#include <bits/stdc++.h>

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
		int start = 0;
		int end = v.size() - 1;
		int ans = 0;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (v[mid] < temp[i])
			{
				start = mid + 1;
			}
			else if (v[mid] > temp[i])
			{
				end = mid - 1;
			}
			else
			{
				ans = mid;
				break;
			}

		}
		cout << ans << " ";
	}

	return 0;
}
