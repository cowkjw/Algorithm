#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m;
int board[51][51];
int vis[51][51];
int ans1 = 1, ans2 = -1, ans3 = -1;
int area[2500];
void go(int x,int y)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	int cnt = 1;
	vis[x][y] = ans1;
	
	while (!q.empty())
	{
		int cx, cy;
		tie(cx, cy) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (board[cx][cy] & (1 << i)) continue;
			int nx, ny;
			switch (i)
			{
			case 0: // 서
				nx = cx;
				ny = cy - 1;
				break;
			case 1: //북
				nx = cx-1;
				ny = cy;
				break;
			case 2:// 동
				nx = cx;
				ny = cy + 1;
				break;
			case 3: //남
				nx = cx+1;
				ny = cy;
				break;
			}
			if (vis[nx][ny]) continue;
			cnt++;
			vis[nx][ny] = ans1;
			q.push({ nx,ny });
		}
	}
	area[ans1] = cnt;
	ans2 = max(cnt, ans2);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j]) continue;
			go(i, j);
			ans1++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + 1 < m)
			{
				int a = vis[i + 1][j];
				int b = vis[i][j];
				if (a != b) 
				{
					ans3 = max(ans3, area[a] + area[b]);
				}
			}
			if (j + 1 < n)
			{
				int a = vis[i][j + 1];
				int b = vis[i][j];
				if (a != b) 
				{
					ans3 = max(ans3, area[a] + area[b]);
				}
			}
		}
	}
	cout << ans1-1 << '\n' << ans2 << "\n" << ans3;
	return 0;
}