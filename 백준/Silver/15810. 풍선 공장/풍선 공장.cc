#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321


int parent[1001];

int Find(int u)
{
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
	u = Find(u);
	v = Find(v);
	if (u != v)
		parent[u] = v;
}


int n, m, d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	vector<int> ballon(n , 0);
	for (int i = 0; i < n; i++)
	{
		cin >> ballon[i];
	}
	sort(ballon.begin(), ballon.end());
	ll l = 1, r = 1e18;
	ll ans = 1e18;
	while (l<=r)
	{
		ll mid = (l + r) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += mid / ballon[i];
			if (cnt >= m)
				break;
		}
		if (cnt >= m)
		{
			ans = min(mid, ans);
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
		
	}
	cout << ans;
	return 0;
}
