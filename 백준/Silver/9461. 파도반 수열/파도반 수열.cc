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
#include <numeric>
using namespace std;
#define INF 987654321

long long dp[101];
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		fill(dp, dp + n, 0);
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;

		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 2] + dp[i - 3];
		}

		cout << dp[n] << '\n';
	}
	return 0;
}
