#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<int> v;
int t, n, m;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			int num;
			cin >> num;

			if (upper_bound(v.begin(), v.end(), num) != v.end())
			{
				sum += v.size() - (upper_bound(v.begin(), v.end(), num) - v.begin());
			}
		}
		cout << sum << '\n';
	}

	return 0;
}
