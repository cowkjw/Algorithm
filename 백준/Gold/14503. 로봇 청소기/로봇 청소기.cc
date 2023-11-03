#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
//vector<pair<int, int>> del{ {1,1} ,{1,-1} ,{-1,1} ,{-1,-1} ,{1,0} ,{-1,0} ,{0,1} ,{0,-1} }; // 8방향
const vector<pair<int, int>> dir{ {-1,0} ,{0,1} ,{1,0} ,{0,-1} }; // 북 동 남 서
int room[51][51];
int n, m;
// 0 북 1 동 2 남 3 서

pair<int, int> s;
int look;
int ret;
void BFS()
{
	queue<pair<int, int>> q;
	q.push(s);
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		if (room[x][y] == 0) ret++, room[x][y] = 2;
		bool clear = false;
		for (int i = 0;i<4;i++)
		{
			look = (look + 3) % 4;
			int nx = x + dir[look].first;
			int ny = y + dir[look].second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; //벽을 넘은 경우
			if (room[nx][ny] == 0)
			{
				q.push({ nx,ny });
				clear = true; // 청소 가능
				break;
			}
		}
		if (!clear)
		{
	
			int bx = x - dir[look].first;
			int by = y - dir[look].second;
			if (bx < 0 || by < 0 || bx >= n || by >= m||room[bx][by]==1) break; // 후진 불가능
			q.push({ bx,by }); // 후진
		}
	}
}

int main()
{
	cin >> n >> m;
	cin >> s.first >> s.second >> look;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
		}
	}

	BFS();
	cout << ret;
	return 0;
}


