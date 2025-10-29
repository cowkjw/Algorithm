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
int dp[100001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= n; i++)
	{
		// 선택 안한 경우
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i-1][2])%9901;
	   // 첫번째 선택
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%9901;
		// 두번째 선택
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}
	cout <<(dp[n][0]+dp[n][1]+dp[n][2]) % 9901;

	return 0;
}
