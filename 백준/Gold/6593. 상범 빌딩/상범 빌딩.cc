#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321
int l, r, c;
int vis[31][31][31]; // 무한 루프 체크
char board[31][31][31]; // 무한 루프 체크
const int dx[]{ 0,0, 0,1,0,-1 };
const int dy[]{ 0,0,1,0,-1,0 };
const int dz[]{ -1,1,0,0,0,0 };
int sx, sy,sz, ex, ey,ez;

struct Pos
{
	int y, x, z;
};

bool Check(int ny, int nx, int nz)
{
	return (ny < 0 || nx < 0 || nz < 0 || ny >= r || nx >= c || nz >= l);
}

void BFS(int y, int x, int z) // 행 열 층
{
	queue<Pos> q;
	vis[y][x][z] = 1;
	q.push({ y, x,z });

	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();
		
		if (cur.y == ey && cur.x == ex && cur.z == ez) return;

		for (int i = 0; i < 6; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			int nz = cur.z + dz[i];

			if (Check(ny, nx, nz)) continue;
			if (vis[ny][nx][nz]||board[ny][nx][nz]=='#') continue;

			q.push({ ny,nx,nz });
			vis[ny][nx][nz] = vis[cur.y][cur.x][cur.z] + 1;
		}
	}
}

void Init()
{
	memset(board, ' ', sizeof(board));
	memset(vis, 0, sizeof(vis));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		cin >> l >> r >> c;
		if (l == 0) break;
		Init();
		
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> board[j][k][i];//  행 열 층
					if (board[j][k][i] == 'S') sy = j, sx = k, sz = i;
					else if (board[j][k][i]=='E') ey = j, ex = k, ez = i;
				}
			}
		}
		BFS(sy, sx, sz);
		if (vis[ey][ex][ez] == 0) cout << "Trapped!\n";
		else cout << "Escaped in " << vis[ey][ex][ez] - 1 << " minute(s).\n";
	}

	return 0;
}
