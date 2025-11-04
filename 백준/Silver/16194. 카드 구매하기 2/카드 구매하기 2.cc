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

int dp[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n;

	vector<int> card(n+1, 0);
	fill(dp, dp + 1001, INF);
	for (int i = 1; i <= n; i++)
	{
		cin >> card[i];
		dp[i] = card[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n];

	return 0;
}
