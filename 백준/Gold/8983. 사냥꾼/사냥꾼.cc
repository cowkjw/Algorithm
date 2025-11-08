#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
#include <sstream>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l;
	cin >> m >> n >> l;

	vector<ll> sa(m);
	for (int i = 0; i < m; i++) cin >> sa[i];
	sort(sa.begin(), sa.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		if (y > l) continue;
	
		ll left = x - (l - y);
		ll right = x + (l - y);
		auto it = lower_bound(sa.begin(), sa.end(), left);
		if (it != sa.end() && *it <= right) ans++;
	}
	cout << ans;
	return 0;
}