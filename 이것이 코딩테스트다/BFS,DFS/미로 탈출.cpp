#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321

using namespace std;



int n, m;
vector<pair<int, int>> delta{ {1,0},{-1,0},{0,1},{0,-1} }; // 상하좌우 
vector<vector<int>> dist(201, vector<int>(201)); // 거리체크 2차원 벡터
void BFS(vector<string>& board, int x, int y)
{
	queue<pair<int, int>> q;

	q.push({ x,y });

	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = delta[dir].first + cur.first;
			int ny = delta[dir].second + cur.second;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;



			if (board[nx][ny] == '1' && dist[nx][ny] == 0)
			{
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	vector<string> board(n); //보드 n개로 행 초기화

	for (int i = 0; i < n; i++)
	{
		cin >> board[i]; // 문자열 입력
	}

	BFS(board, 0, 0);

	cout << dist[n - 1][m - 1]+1; // 처음 시작을 더함 

	return 0;
}







