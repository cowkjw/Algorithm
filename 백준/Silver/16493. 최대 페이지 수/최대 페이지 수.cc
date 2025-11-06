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

int n, m, d;
int dp[201];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	for (int j = 0; j < m; j++)
	{
		int day, page;
		cin >> day >> page;
		for (int i = n; i >= day; i--)
		{
			dp[i] = max(dp[i], dp[i - day] + page);
		}
	}

	cout << dp[n];

	return 0;
}
