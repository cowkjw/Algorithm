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

using namespace std;
#define INF 987654321

int dp[3][1001];
int color[3][1001];
int main()
{

	int n;
	cin >> n;
	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> color[j][i];
		}
	}

	for (int startColor = 0; startColor < 3; startColor++) // 1층 집의 시작 색
	{
		for (int i = 0; i < 3; i++) // 1층 초기화
		{
			if (startColor == i)
			{
				dp[i][0] = color[i][0];
			}
			else
			{
				dp[i][0] = INF;
			}
		}
		for (int i = 1; i < n; i++)  // i-1, i+1이 다르게 하기 위해서 DP돌림
		{
			dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + color[0][i];
			dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + color[1][i];
			dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + color[2][i];
		}
		for (int lastColor = 0; lastColor < 3; lastColor++)
		{
			if (lastColor != startColor) // 1층과 다른집이면
			{
				ans = min(ans, dp[lastColor][n - 1]);
			}
		}
	}

	cout << ans;
	return 0;
}
