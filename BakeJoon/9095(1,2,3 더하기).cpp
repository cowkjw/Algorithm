#include <bits/stdc++.h>
using namespace std;



int dp[13];
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--)
	{

		//fill(dp, dp + 13, 0);
		int num;
		cin >> num;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= num; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);
		}

		cout << dp[num] << '\n';

	}

}


