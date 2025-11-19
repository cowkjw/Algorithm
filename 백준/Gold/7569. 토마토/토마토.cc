#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
#include <sstream>
#include <cstring>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int dh[] = { -1,1};

struct Pos
{
	int h, y, x;
};

int board[101][101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> k;
	queue<Pos> q;
	int tomato = 0;
	for (int h = 0; h < k; h++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> board[h][i][j];

				if (board[h][i][j] == 1)
				{
					q.push({ h, i, j });
				}

				if (board[h][i][j] != -1)
				{
					tomato++;
				}
			}
		}
	}

	if (tomato == q.size())
	{
		cout << 0;
		return 0;
	}
	tomato -= q.size();
	int ans = -1;
	while (!q.empty())
	{
		auto [h, y, x] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || board[h][ny][nx] != 0) continue;
			board[h][ny][nx] = board[h][y][x] + 1;
			q.push({ h,ny,nx });
			ans = max(ans, board[h][ny][nx]);
			tomato--;
		}

		for (int dir = 0; dir < 2; dir++)
		{
			int nh = h + dh[dir];

			if (nh < 0 || nh >= k || board[nh][y][x] != 0) continue;
			board[nh][y][x] = board[h][y][x] + 1;
			q.push({ nh,y,x });
			ans = max(ans, board[nh][y][x]);
			tomato--;
		}
	}
	if (tomato != 0) cout << -1;
	else cout << ans-1;
	return 0;
}