#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
vector<string> open;
vector<string> boom;

int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, -1, 1 };

int bfs(int x, int y)
{
	queue<pair<int, int>>q;
	int vis[10][10];
	memset(vis, 0, sizeof(vis));
	q.push({ x, y });
	int cnt = 0;

	while (!q.empty())
	{
		int _x, _y;
		tie(_x, _y) = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = dx[i] + _x;
			int ny = dy[i] + _y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (vis[nx][y]) continue;
			if (boom[nx][ny] == '*') cnt++;
		}
	}

	return cnt;
}

void Boom()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << boom[i][j];
		}
		cout << '\n';
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		boom.push_back(str);
	}
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		open.push_back(str);
	}
	vector<vector<char>>v(n, vector<char>(n));
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (boom[i][j] == '.' && open[i][j] == 'x')
			{
				v[i][j] = bfs(i, j) + '0';
			}
			else if (boom[i][j] == '*' && open[i][j] == 'x')
			{
				flag = true;
			}
			else if(open[i][j]=='.')
			{
				v[i][j] = '.';
			}
		}
	}
	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(boom[i][j]=='*')v[i][j]='*';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}
}