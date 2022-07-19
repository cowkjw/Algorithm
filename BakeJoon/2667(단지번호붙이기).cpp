#include <bits/stdc++.h>
using namespace std;

int vis[102][102];
int dx[4] = { 1,0,-1,0 }; // 하 우 상 좌
int dy[4] = { 0,1,0,-1 };
int n;
int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> board;
	vector<int> ans;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j]=='0' || vis[i][j] == 1) // 구역이 아니거나 방문했다면 
				continue;

			queue<pair<int, int>> q;

			vis[i][j] = 1;
			q.push({ i,j });
			int area = 1; // 넓이
			cnt++;// 구역 체크

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) // 보드 범위 밖
						continue;
					if (board[nx][ny] =='0' || vis[nx][ny] == 1)// 갈 수 없는 구역이거나 구역이 방문했다면
						continue;
					q.push({ nx,ny }); // 집어넣고 상하좌우 체크
					vis[nx][ny] = 1; // 방문 체크
					area++; // 넓이 체크
				}
			}

			ans.push_back(area);
		}
	}

	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (auto i : ans)
		cout << i << '\n';



	return 0;

}

