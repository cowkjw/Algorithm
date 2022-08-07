#include <bits/stdc++.h>
using namespace std;




int dp[1001];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;


	dp[1] = 1; // 1일때 경우의 수
	dp[2] = 3; // 2일때 경우의 수

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007; // i-1일때 1가지 i-2일때 2가지 
	}
	cout << dp[n];


	return 0;


}
