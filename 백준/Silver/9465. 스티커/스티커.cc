#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
#define MOD 1000000
using namespace std;

int n, ans;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<vector<int>> wall(2, vector<int>(n));
		vector<vector<int>> dp(2, vector<int>(n));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> wall[i][j];
			}
		}
		dp[0][0] = wall[0][0];
		dp[1][0] = wall[1][0];

		for (int i = 1; i < n; i++)
		{

			dp[0][i] = max(dp[1][i - 1] + wall[0][i], dp[0][i - 1]); // 위쪽 선택
			dp[1][i] = max(dp[0][i - 1] + wall[1][i], dp[1][i - 1]); // 아래쪽 선택
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}


	return 0;
}