#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
int n, k;
int dp[100001];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= w; j--)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];

	return 0;
}


