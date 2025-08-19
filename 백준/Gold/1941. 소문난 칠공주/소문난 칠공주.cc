#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321

vector<string> board;

int dx[4] = { 0, 0, -1, 1 }; // 상하좌우
int dy[4] = { -1, 1, 0, 0 }; // 상하좌우
int ans = 0;
bool visited[5][5];

void isValid(int idx, vector<int>& vecSelected)
{
	if (vecSelected.size() == 7)
	{
		fill(&visited[0][0], &visited[0][0] + sizeof(visited), false);
		int x = vecSelected[0] / 5; // 0~4
		int y = vecSelected[0] % 5; // 0~4
		queue<pair<int, int>> q;
		q.push({ x, y });
		visited[x][y] = true;

		int ida = 0;
		int connected = 0; // 연결된 사람 수
		if (board[x][y] == 'S') // 이다솜파
			ida++;
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			connected++; // 연결된 사람 수 증가
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
					continue;
				if (visited[nx][ny]) 
					continue;
				// 연결되는지
				for (int j = 0; j < 7; j++)
				{
					if (vecSelected[j] == nx * 5 + ny)
					{
						visited[nx][ny] = true;
						q.push({ nx, ny });
						if (board[nx][ny] == 'S')
							ida++;
						break;
					}
				}
			}
		}
		if (ida >= 4&&connected == 7)
		{
			ans += 1; // 이다솜파가 4명 이상
		}
		return;
	}

	for (int i = idx; i < 25; i++)
	{
		vecSelected.push_back(i);
		isValid(i + 1, vecSelected);
		vecSelected.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	board.resize(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> board[i];
	}

	// 7명의 이름으로
	// 7명은 서로 가로 세로로 인접해야한다.
	// 이다솜파로는 이뤄지지 않아도 되지만 최소 4명이상
	vector<int> vecSelected;
	isValid(0,vecSelected);

	cout << ans;
	return 0;
}