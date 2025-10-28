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

int n, m, d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	ll l = 1, r = *max_element(vec.begin(),vec.end());

	ll ans = 0;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += vec[i] / mid;
		}
		if (cnt >= m)
		{
			ans = max(mid, ans);
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << r;
	return 0;
}
