#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
int n;
double m;
int dp[10001];

int main()
{

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0.0) break;
		fill(dp, dp + 10001, 0);
		int M = (int)(m * 100 + 0.5);
		for (int i = 0; i < n; i++)
		{
			int c;
			double p;
			cin >> c >> p;
			int P = (int)(p*100+0.5);
			for (int j = P; j <= M; j++)
			{
				dp[j] = max(dp[j], dp[j -P]+c);
			}
		}
		cout << dp[M]<<'\n';
	}
	return 0;
}


