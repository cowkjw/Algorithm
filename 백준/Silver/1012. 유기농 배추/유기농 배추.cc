#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

vector<pair<int, int>> dir {{1, 0}, { 0,1 }, { -1,0 }, { 0,-1 }};// { 1, 1 }, { 1,-1 }, { -1,1 }, { -1,-1 }};
int board[101][101];
int n, m;

void dfs(int x, int y)
{
	if (board[x][y] == 2 || board[x][y] == 0) return;
	if (x < 0 || y < 0 || x >= n || y >= m) return;

	board[x][y] = 2;
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x, y - 1);

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int pos;
		for (int i = 0; i < 100; i++)
		{

			fill(board[i], board[i] + 100, 0);
		}

		cin >> n >> m >> pos;

		while (pos--)
		{
			int a, b;
			cin >> a >> b;
			board[a][b] = 1;
		}
		int answer = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1)
				{
					dfs(i, j);
					answer++;
				}
			}
		}

		cout << answer << "\n";
	}
	return 0;
}