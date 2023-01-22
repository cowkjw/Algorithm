#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;


long long dp[91];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1;
	dp[2] = 1;
	int n;
	cin >> n;

	for (int i = 3; i <= n; i++)
	{
		dp[i] += dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];

	return 0;
}