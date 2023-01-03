#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second

using namespace std;

vector<pair<int, int>> dir = { {0,-1}, {-1,0},{0,1} ,{1,0} };// 북 동 남 서

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b, d;
	cin >> n >> m;
	cin >> a >> b >> d;

	// 북은 x-1 남은 x+1 동 
	pair<int, int> startPos{ a,b };

	vector<vector<int>> board(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j]; // 1 바다 0 육지
		}
	}


	int cnt = 0; //회전 횟수
	int ans = 1; // 자기 시작위치
	auto curPos = startPos;
	board[curPos.X][curPos.Y]++;
	pair<int,int> nextPos; // 다음 위치 
	while (true)
	{
		d--;
		if (d < 0)
		{
			d = 3;
		}

		nextPos = { (curPos.X + dir[d].X), (curPos.Y + dir[d].Y) }; // 다음으로 이동할 곳

		if (nextPos.X < 0 || nextPos.X >= n || nextPos.Y < 0 || nextPos.Y >= m)
			continue;
		if (board[nextPos.X][nextPos.Y] == 0) // 0이라면
		{
			board[nextPos.X][nextPos.Y] = 1;
			curPos = nextPos; // 현재 위치를 갱신
			ans++; // 이동했으므로 ++
			cnt = 0; // 순회를 다시 0으로 
			continue;
		}
		else
		{
			cnt++;
		}

		if (cnt == 4) // 모든 방향 다 순회
		{
			nextPos = { (curPos.X - dir[d].X), (curPos.Y - dir[d].Y) }; // 한칸 뒤
			if (nextPos.X < 0 || nextPos.X >= n || nextPos.Y < 0 || nextPos.Y >= m)
				continue;
			if (board[nextPos.X][nextPos.Y] == 0)
			{
				curPos = nextPos; // 한칸 뒤 이동
				cnt = 0;
				continue;
			}
			else
			{
				break;
			}

		}
		
	}

	cout << ans;

	return 0;
}







