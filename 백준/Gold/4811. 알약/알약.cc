#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;

int n;
ll dp[31][31];
ll go(int whole,int nWhole)
{
	if (whole == 0 && nWhole == 0) return 1;

	if (dp[whole][nWhole]) return dp[whole][nWhole];

	if (whole > 0) dp[whole][nWhole] += go(whole - 1, nWhole+1);
	if (nWhole > 0) dp[whole][nWhole] += go(whole, nWhole-1);

	return dp[whole][nWhole];
}
int main()
{
	while (1)
	{
		cin >> n;
		if (!n) break;

		cout<<go(n - 1, 1)<<'\n';
	}
}


