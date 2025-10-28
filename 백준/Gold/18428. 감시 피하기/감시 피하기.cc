#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321


int n, m, d;
char board[6][6];
set<pii> s;
vector<pii> teachers;
bool found = false;
bool IsValid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < n && y < n);
}
bool Check()
{

	for (auto& [tx, ty] : teachers)
	{
		// 4방향 체크
		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };

		for (int d = 0; d < 4; d++)
		{
			int nx = tx + dx[d];
			int ny = ty + dy[d];

			while (IsValid(nx, ny))
			{
				// 장애물 만남
				if (s.find({ nx, ny }) != s.end()) break;
				if (board[nx][ny] == 'S') return false;

				nx += dx[d];
				ny += dy[d];
			}
		}
	}

	// 모든 선생님이 학생을 못 봤음 → 성공
	return true;
}

void Back(int x,int y)
{
	if (found) return;
	if (s.size() == 3)
	{
		if (Check())
		{
			found = true;
		}
		return;
	}

	s.insert({x,y});

	for (int i = x; i < n; i++) 
	{
		for (int j = (i == x ? y + 1 : 0); j < n; j++)
		{
			if (board[i][j] == 'X'&&s.count({i,j}) == 0)
			{
				Back(i,j);
			}
		}
	}
	s.erase({ x, y });
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'T')
				teachers.push_back({ i,j });
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'X') // 장애물 놓을 위치
			{
				Back(i, j);
				
			}
		}
	}

	if (found)
	{
		cout << "YES";
	}
	else
		cout << "NO";

	return 0;
}
