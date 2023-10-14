#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int m, n, ret;
int board[1001][1001];
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
vector<pair<int, int>> tomato;
void go(queue<pair<int, int>> q)
{
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		ret = max(board[x][y], ret);

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = dx[dir] + x;
			int ny = dy[dir] + y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == -1 || board[nx][ny] >= 1) continue;
			board[nx][ny] = board[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	return;
}

bool check()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (board[i][j] == 0) return false;
		}
	}
	return true;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			
			if (board[i][j] == 1) tomato.push_back({ i,j });
		}
	}
	queue<pair<int, int>> q;
	for (auto& a : tomato)
	{
		q.push({ a.first,a.second });
	}
	go(q);

	if (!check())
	{
		cout << -1;
	}
	else
	{
		cout << ret - 1;
	}


	return 0;
}
