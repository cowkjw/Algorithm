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


int dp[16][16];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k;
	cin >> n >> m >> k;
	if (k == 0) 
	{
		for (int i = 1; i <= n; i++) dp[i][1] = 1;
		for (int j = 1; j <= m; j++) dp[1][j] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 2; j <= m; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

		cout << dp[n][m];
		return 0;
	}

	int cY = (k - 1) / m + 1;
	int cX = (k - 1) % m + 1;

	fill(&dp[0][0], &dp[15][15], 0);

	for (int i = 1; i <= n; i++) dp[i][1] = 1;
	for (int j = 1; j <= m; j++) dp[1][j] = 1;


	for (int i = 2; i <= cY; i++) // 해당 위치까지는 무조건 가야함
	{
		for (int j = 2; j <= cX; j++)
		{

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	int part1 = dp[cY][cX];

	fill(&dp[0][0], &dp[15][15], 0);

	int height = n - cY + 1;
	int width = m - cX + 1;

	for (int i = 1; i <= height; i++) dp[i][1] = 1;
	for (int j = 1; j <= width; j++) dp[1][j] = 1;

	for (int i = 2; i <= height; i++)
		for (int j = 2; j <= width; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

	int part2 = dp[height][width];

	cout << part1 * part2;
	return 0;
}
