#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n;
vector<int> tri[501];
int dp[501][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int num;
			cin >> num;
			tri[i].push_back(num);
		}

	}

	dp[1][0] = tri[1][0];

	int maxSum = dp[1][0];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < tri[i].size(); j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			}
			else if (j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];

			}
			maxSum = max(maxSum, dp[i][j]);
		}
	}

	cout << maxSum;
}






