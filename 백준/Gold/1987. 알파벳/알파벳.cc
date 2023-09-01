#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

vector<pair<int, int>> dir{ {1, 0}, { 0,1 }, { -1,0 }, { 0,-1 } };
int n, m, ret = -1;
vector<string> board;
int vis[27];
void go(int x, int y, int cnt)
{
	ret = max(cnt, ret);
	for (const auto& di : dir)
	{
		int nx = x + di.first;
		int ny = y + di.second;
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (vis[board[nx][ny] - 'A']) continue;
		vis[board[nx][ny] - 'A'] = 1;
		go(nx, ny, cnt + 1);
		vis[board[nx][ny] - 'A'] = 0;
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}
	vis[board[0][0] - 'A'] = 1;
	go(0, 0, 1);
	cout << ret;

}
