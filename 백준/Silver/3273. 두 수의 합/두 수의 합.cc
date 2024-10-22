#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, x;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cin >> x;
	int s = 0;
	int e = n-1;
	int ret = 0;
	while (s < e && e < n)
	{
		int sum = v[s] + v[e];

		if (sum < x)
		{
			s++;
		}
		else if (sum > x)
		{
			e--;
		}
		else
		{
			e--;
			ret++;
		}
	}
	cout << ret;
	return 0;
}