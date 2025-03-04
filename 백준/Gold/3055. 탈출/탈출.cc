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

using namespace std;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };
char board[51][51];
int vis[2][51][51];
int r, c;

struct Pos
{
	int min, x, y;
};

bool IsValid(int x, int y)
{
	return (x >= 1 && y >= 1 && x <= r && y <= c && board[x][y] != 'X');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> r >> c;
	queue<Pos> q;
	pair<int, int> des;
	Pos start;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == '*')
			{
				q.push({ 1, i, j });
				vis[0][i][j] = 1;
			}
			else if (board[i][j] == 'D')
			{
				des = { i,j };
			}
			else if (board[i][j] == 'S')
			{
				start = { 1,i,j };
				vis[1][i][j] = 1;
			}
		}
	}

	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nm = cur.min + 1;
			if (IsValid(nx, ny) == false) continue;

			if (!vis[0][nx][ny] && board[nx][ny] != 'D')
			{
				vis[0][nx][ny] = nm;
				q.push({ nm, nx, ny });
			}
		}

	}
	q.push(start);
	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();

		if (cur.x == des.first && cur.y == des.second)
		{
			cout << cur.min-1;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nm = cur.min + 1;
			if (IsValid(nx, ny) == false) continue;

			// 아직 간적이 없고 물이 없거나 물이 나보다 늦게 도착하는 경우
			if (!vis[1][nx][ny]&& (vis[0][nx][ny] == 0 || vis[0][nx][ny] > nm))
			{
				vis[1][nx][ny] = nm;
				q.push({ nm, nx, ny });
			}
		}
	}
	cout << "KAKTUS";
	return 0;
}
