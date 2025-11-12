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


int dp[1001][1001];
int candy[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> candy[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		dp[1][i] = candy[1][i] + dp[1][i - 1];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j == 1)
			{
				dp[i][j] = dp[i - 1][j] + candy[i][j];
			}
			else
			{
				dp[i][j] = max({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] }) + candy[i][j];
			}
		}
	}

	cout << dp[n][m];

	return 0;
}
