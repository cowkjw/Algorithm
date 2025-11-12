#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;


int dp[31][31];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i <= 30; i++)
	{
		dp[i][1] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	cin >> n >> m;

	cout<<dp[n][m];

	return 0;
}
