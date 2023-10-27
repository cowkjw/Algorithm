#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 987654321


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		int m;
		cin >> m;
		vector<int> v2(m);
		for (int i = 0; i < m; i++)
		{
			cin >> v2[i];
		}

		for (const auto i : v2)
		{
			int start = 0;
			int end = n - 1;

			while (1)
			{
				int mid = (start + end) / 2;

				if (v[mid] > i)
				{
					end = mid - 1;
				}
				else if (v[mid] < i)
				{
					start = mid + 1;
				}
				else
				{
					cout << "1\n";
					break;
				}

				if (start > end)
				{
					cout << "0\n";
					break;
				}
			}
		}
	}

	return 0;
}
