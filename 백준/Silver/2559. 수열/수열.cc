#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001];
int main()
{
	int n, k;
	cin >> n >> k;

	vector<int>vec(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	dp[0] = 0;
	dp[1] = vec[0];
	int ans = -1e9;
	for (int i = 2; i <= n; i++)
	{
		dp[i]+= dp[i-1]+vec[i-1];
	}

	for (int i = 0; i <= n-k; i++)
	{
		ans = max(dp[i + k] - dp[i], ans);
	}
	cout << ans;
	return 0;
}