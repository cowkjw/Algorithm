#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second


using namespace std;



int dp[1001];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	for (int i = 4; i <= n; i++)
	{
		if (!(dp[i - 1] | dp[i - 3])) dp[i] = 1;
	}
	if (dp[n] != 0) cout << "SK";
	else cout << "CY";
	return 0;
}
