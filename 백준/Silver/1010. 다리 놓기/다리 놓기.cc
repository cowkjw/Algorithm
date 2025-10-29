#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321


int n, m, d;
unordered_set<int> broken;
int dp[31][31];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i <= 30; i++)
	{
		dp[i][0] = dp[i][i] = 1;
		for (int j =1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	//dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
	while (t--)
	{
		cin >> n >> m; // 서 ,동
		cout << dp[m][n] << '\n';
	}

	return 0;
}
