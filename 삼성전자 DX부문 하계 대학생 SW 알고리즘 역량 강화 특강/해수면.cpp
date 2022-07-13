#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int t;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void DecreaseHegiht(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)
				continue;
			else
				board[i][j]--;

		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	int count = 0;
	while (t--)
	{
		count++;
		int n;
		int mx = 0; //해수면 높이 최댓값
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
				mx = max(mx, board[i][j]);
			}



		if (mx == 0)
		{
			cout << "#" << count << " " << 1 << "\n";
			break;
		}

		int num = 1;// 구역의 수
		for (int year = 1; year <= mx; year++)
		{
			DecreaseHegiht(n);
			int temp = 0;
			bool vis[102][102] = {};
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (board[i][j] == 0 || vis[i][j]) // 이미 방문했거나 높이가 0인경우
						continue;
					temp++;
					queue<pair<int, int>> q;
					vis[i][j] = 1; // 큐에 넣기전 방문처리
					q.push({ i,j });


					while (!q.empty())
					{

						pair<int, int> cur = q.front();
						q.pop();

						for (int dir = 0; dir < 4; dir++) //상하좌우 체크
						{
							int nx = cur.first + dx[dir]; // x좌표
							int ny = cur.second + dy[dir]; // y좌표

							if (nx < 0 || nx >= n || ny < 0 || ny >= n) // 범위 계산
								continue;
							if (vis[nx][ny] || board[nx][ny] == 0) // 이미 방문했거나 해수면이 0이라면
								continue;
							vis[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
			num = max(num, temp);
		}
		cout << "#" << count << " " << num << "\n";

	}
}