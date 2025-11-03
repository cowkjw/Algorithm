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

int n, m, d;

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };

char board[301][301];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 일부 칸 폭탄 설치
	// 다음 1초 동안은 아무것도 안함
	// 설치 되지 않은 모든 칸에 폭탄 설치
	// 3초 전에 설치된 폭탄 모두 폭발

	int r, c;
	cin >> r >> c >> n;

	vector<pii> boomPos;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'O')
			{
				boomPos.push_back({ i,j });
			}
		}
	}

	int curTime = 1;
	if (n == 1)
	{
		// 초기 상태 출력

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << board[i][j];
			}
			cout << '\n';
		}
		return 0;
	}
	else if (n % 2 == 0)
	{
		// 모든 칸 폭탄

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << 'O';
			}
			cout << '\n';
		}
		return 0;
	}
	else if (n % 4 == 3)
	{
		// 첫 번째 폭발 후 상태
		vector<pii> newBoomPos; // 폭탄 설치
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if ('.' == board[i][j])
				{
					newBoomPos.push_back({ i,j });
					board[i][j] = 'O';
				}
			}
		}

		for (auto pos : boomPos)
		{
			auto [y, x] = pos;
			board[y][x] = '.';
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
				board[ny][nx] = '.';
			}
		}
		boomPos = newBoomPos;
		for (auto it = boomPos.begin(); it != boomPos.end();)
		{
			auto pos = *it;
			if (board[pos.first][pos.second] == '.')
			{
				it = boomPos.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	else if (n % 4 == 1)
	{
		for (int cnt = 0; cnt < 2; cnt++)
		{


			vector<pii> newBoomPos; // 폭탄 설치
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if ('.' == board[i][j])
					{
						newBoomPos.push_back({ i,j });
						board[i][j] = 'O';
					}
				}
			}

			for (auto pos : boomPos)
			{
				auto [y, x] = pos;
				board[y][x] = '.';
				for (int dir = 0; dir < 4; dir++)
				{
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
					board[ny][nx] = '.';
				}
			}
			boomPos = newBoomPos;
			for (auto it = boomPos.begin(); it != boomPos.end();)
			{
				auto pos = *it;
				if (board[pos.first][pos.second] == '.')
				{
					it = boomPos.erase(it);
				}
				else
				{
					++it;
				}
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}
