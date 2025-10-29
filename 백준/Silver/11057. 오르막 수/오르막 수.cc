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
int dp[1001][11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int j = 0; j <= 9; j++)
		dp[1][j] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = 1; // 0은 어떤 길이든 그 자리에 오려면 1가지밖에 없음
		for (int j = 1; j<=9;j++)
		{
			// 현재 i의 길이에 j 수가 올 수 있는 가지수
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%10007;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans += dp[n][i];
	}
	cout << ans % 10007;
	return 0;
}
