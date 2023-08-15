#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

vector<pair<int, int>> dir {{1, 0}, { 0,1 }, { -1,0 }, { 0,-1 }};

int dist[101][101];
int n, m;
vector<string> board;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}

	queue<pair<int, int>> q;
	q.push({0,0});
	dist[0][0] = 1;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (const auto di : dir)
		{
			int nx = cur.first + di.first;
			int ny = cur.second + di.second;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny]) continue;
			if (board[nx][ny]=='1')
			{
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}
		}
	}
	cout << dist[n-1][m-1];
	return 0;
}