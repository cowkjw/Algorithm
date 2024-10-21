#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][3];
int n, k;
vector<vector<int>>vec(1001);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		vec[i] = { r,g,b };
	}
	dp[0][0] = vec[0][0]; //r
	dp[0][1] = vec[0][1]; //g
	dp[0][2] = vec[0][2]; // b

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i - 1][1],dp[i-1][2]) + vec[i][0];
		dp[i][1] = min(dp[i -1][0], dp[i - 1][2]) + vec[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + vec[i][2];

	}
	int ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	cout << ans;
	return 0;
}