#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


vector<pair<int, int>> dir{ {1, 0}, { 0,1 }, { -1,0 }, { 0,-1 } };
int n, m, ret;
vector<string> board;
int x1, Y1, x2, y2;
int vis[301][301];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> x1 >> Y1 >> x2 >> y2;
	x1--, x2--, Y1--, y2--;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}

	while (board[x2][y2] != 'X')
	{
		fill(&vis[0][0], &vis[0][0] + 301 * 301, 0);
		queue<pair<int, int>> q;
		q.push({ x1,Y1 });
		vis[x1][Y1] = 1;
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();

			for (const auto& di : dir)
			{
				int nx = x + di.first;
				int ny = y + di.second;

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (vis[nx][ny]) continue;
				if (board[nx][ny] == '#') // 도착점
				{
					board[nx][ny] = 'X';
					break;
				}
				if (board[nx][ny] == '1') // 학생
				{
					vis[nx][ny] = 1; // 방문처리
					board[nx][ny] = '0'; // 쓰러뜨림
					continue;
				}
				vis[nx][ny] = 1; // 방문처리
				q.push({ nx,ny }); // 0이면 계속 넣어서 퍼져나가게
			}
		}
		ret++;
	}

	cout << ret;
}