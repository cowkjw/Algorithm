#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[16];
int n, k;
vector<pair<int, int>> vec(16);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[i] = { a,b };
	}

	for (int i = n; i >= 0; i--)
	{
		if (i + vec[i].first > n)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + vec[i].first] + vec[i].second, dp[i + 1]); // 이전의 값들로 부터 
		}
	}
	cout << dp[0];
	return 0;
}