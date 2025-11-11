#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> board;
	for (int i = 0; i < 12; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}
	int ans = 0;
	// 5개의 색상을 확인하기 각 위치에서 
	while (true)
	{
		bool founded = false;
		vector<vector<int>> vis(12, vector<int>(6));

		for (int row = 0; row < 12; row++)
		{
			for (int col = 0; col < 6; col++)
			{
				if (board[row][col] == '.' || vis[row][col]) continue;
				vector<pii> group;
				queue<pii> q;
				vis[row][col] = 1;
				q.push({ row,col });
				group.push_back({ row,col });

				while (!q.empty())
				{
					auto [y, x] = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12) continue;
						if (vis[ny][nx] || board[ny][nx] == '.' || board[ny][nx] != board[y][x]) continue;
					
						vis[ny][nx] = 1;
						group.push_back({ ny,nx });
						q.push({ ny,nx });
					}
				}
				if (group.size() >= 4)
				{
					for (const auto& pos : group)
					{
						board[pos.first][pos.second] = '.';
					}
					founded = true;
				}
			}
		}
		if (!founded) break;
		ans++;
		for (int col = 0; col < 6; col++)
		{
			int gravity = 11;
			for (int row = 11; row >= 0; row--)
			{
				if (board[row][col] != '.')
				{
					auto color = board[row][col];
					board[row][col] = '.';
					board[gravity--][col] = color;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
