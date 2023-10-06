#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int r, c, t;
int board[51][51];
int temp[51][51];
vector<pair<int, int>> fresh;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int dx[4]{ 0,-1,0,1 };
int dy[4]{ 1,0,-1, 0 };
int dx2[4]{ 0,1,0, -1 };
int dy2[4]{ 1,0,-1, 0 };

void Diffuse()
{
	memset(temp, 0, sizeof(temp));
	queue<pair<int, pair<int, int>>> dust; // 먼지 위치
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == -1 || board[i][j] == 0)continue;
			dust.push({ board[i][j],{i,j} });
		}
	}

	while (!dust.empty())
	{
		auto cur = dust.front();
		dust.pop();
		int a = cur.first;// 먼지
		int x = cur.second.first;
		int y = cur.second.second;
		int nextDust = a / 5; // 전파 먼지
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = dx[dir] + x;
			int ny = dy[dir] + y;

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (board[nx][ny] == -1) continue; // 공기청정기
			temp[nx][ny] += nextDust;
			board[x][y] -= nextDust;
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			board[i][j] += temp[i][j];
		}
	}
}

vector<pair<int, int>> chung(int sx, int sy, int dx[], int dy[])
{
	vector<pair<int, int>> v;
	int cnt = 0;
	int x = sx;
	int y = sy;
	while (true)
	{
		int nx = x + dx[cnt];
		int ny = y + dy[cnt];
		if (ny == sy && nx == sx)break;
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
		{
			cnt++;
			nx = x + dx[cnt];
			ny = y + dy[cnt];
		}
		if (ny == sy && nx == sx)break;
		y = ny; x = nx;
		v.push_back({ nx, ny });
	}
	return v;
}

void go(vector<pair<int, int>>& v)
{
	for (int i = v.size() - 1; i > 0; i--) {
		board[v[i].first][v[i].second] = board[v[i - 1].first][v[i - 1].second];
	}
	board[v[0].first][v[0].second] = 0;
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == -1) fresh.push_back({ i,j }); // 공기 청정기 넣기
		}
	}
	v1 = chung(fresh[0].first, fresh[0].second, dx, dy);
	v2 = chung(fresh[1].first, fresh[1].second, dx2, dy2);
	while (t--)
	{
		Diffuse();
		go(v1);
		go(v2);
	}
	int ret = 0;
	for (int i = 0; i < r; i++) 
	{
		for (int j = 0; j < c; j++) 
		{
			if (board[i][j] != -1)ret += board[i][j];
		}
	}

	cout << ret;
	return 0;
}
