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
ll dp[101][101];
int board[101][101];

ll DFS(int y, int x)
{
	if (x >= n || y >= n) 
		return 0;
	if (x == n-1 && y == n-1) 
		return 1;
	if (board[y][x] == 0)
		return 0;
	if (dp[y][x] != -1) 
		return dp[y][x];

	int ny = y + board[y][x];
	int nx = x + board[y][x];

	return dp[y][x] = (DFS(ny, x) + DFS(y, nx));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}

	auto ans = DFS(0, 0);
	cout << ans;
	return 0;
}
