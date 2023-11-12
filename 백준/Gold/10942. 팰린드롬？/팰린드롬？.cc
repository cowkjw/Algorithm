#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;


int dp[2001][2001];
int n, m;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = i; j <= n; j++)
		{
			if (i == j) dp[i][j] = 1;
			else if (v[i - 1] == v[j - 1])
			{
				if (j - i == 1) dp[i][j] = 1; // 인접한가
				else dp[i][j] = dp[i + 1][j - 1];
			}
			else dp[i][j] = 0;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}

	return 0;
}


