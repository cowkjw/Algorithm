#include <bits/stdc++.h>
using namespace std;




int dp[1001];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;


	dp[1] = 1; // 1�϶� ����� ��
	dp[2] = 3; // 2�϶� ����� ��

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007; // i-1�϶� 1���� i-2�϶� 2���� 
	}
	cout << dp[n];


	return 0;


}
