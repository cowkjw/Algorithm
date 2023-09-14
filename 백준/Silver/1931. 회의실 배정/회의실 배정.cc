#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
vector<pair<int, int>> v;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ret = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());
	int pre = v[0].first;
	for (int i = 1; i < n; i++)
	{
		if (pre <= v[i].second)
		{
			pre = v[i].first;
			ret++;
		}
	}
	cout << ret;
	return 0;
}