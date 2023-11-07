#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
int n;
int dp[101];
int L[21], J[21];
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> L[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> J[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j > L[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
		}
	}
	cout << dp[100];

	return 0;
}


