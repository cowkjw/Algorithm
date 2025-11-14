#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;

int dp[31];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<ll> up(n);
	vector<ll> low(n);
	for (int i = 0; i < n; i++) cin >> up[i];
	for (int i = 0; i < n; i++) cin >> low[i];
	vector<ll> diff;
	for (int i = 0; i < n; i++)
	{
		diff.push_back( abs(up[i] - low[i]));
	}
	vector<ll> minGap(n);
	minGap[0] = diff[0];
	for (int i = 1; i < n; i++)
	{
		minGap[i] = min(minGap[i - 1], diff[i]);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll bird;
		cin >> bird;
		int s = 0, e = n - 1;
		int ans = -1;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (minGap[mid] >= bird)
			{
				ans = mid;
				s = mid + 1;
			}
			else
			{
				e = mid - 1;
			}
		}
		cout << ans + 1 << '\n';
	}

	return 0;
}
