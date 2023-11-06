#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;

int n, k;
int dp[10001];
int main()
{

	dp[0] = 1;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int coin;
		cin >> coin;
		for (int j = coin; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - coin];
		}
	}

	cout << dp[k];
}


