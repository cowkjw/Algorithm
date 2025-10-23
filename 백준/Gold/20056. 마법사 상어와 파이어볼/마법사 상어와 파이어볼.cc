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
#define INF 987654321

const int dr[]{ -1,-1,0,1,1,1,0,-1 }; // 행 이동
const int dc[]{ 0,1,1,1,0,-1,-1,-1 }; // 열 이동

int n, m,k;

struct FireBall
{
	int dir;
	int speed;
	int mass;
};

vector<vector<vector<FireBall>>> board(51, vector<vector<FireBall>>(51));
vector<vector<vector<FireBall>>> newBoard(51, vector<vector<FireBall>>(51));

void Move(int speed, int& r, int& c, int dir)
{
	int nr = ((r - 1) + dr[dir] * (speed % n) + n) % n + 1;
	int nc = ((c - 1) + dc[dir] * (speed % n) + n) % n + 1;
	r = nr;
	c = nc;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k; //m은 파이어볼 개수

	for (int i = 0; i < m; i++)
	{
		int r, c, mass, speed, dir;
		cin >> r >> c >> mass >> speed >> dir;
		board[r][c].push_back({ dir,speed,mass });
	}

	while (k--)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				newBoard[i][j].clear();

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				// 먼저 이동처리
				if (board[i][j].empty()) continue;

				for (auto& fireball : board[i][j])
				{
					int x = i;
					int y = j;
					Move(fireball.speed, x, y, fireball.dir);
					newBoard[x][y].push_back(fireball);
				}
				board[i][j].clear();
			}
		}
		// 이동 후 처리
		// 2개 이상인 경우 찾기
		board = newBoard;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j<= n; j++)
			{
				if (board[i][j].size() < 2) continue;

				int totalMass = 0;
				int totalSpeed = 0;
				bool allEven = true;
				bool allOdd = true;
				for (auto& fireBall : board[i][j])
				{
					totalMass += fireBall.mass;
					totalSpeed += fireBall.speed;
					if (fireBall.dir % 2 == 0) allOdd = false;
					else allEven = false;
				}
				int newMass = totalMass / 5;
				int newSpeed = totalSpeed / board[i][j].size();
				board[i][j].clear();
				if (newMass == 0) continue;
				if (allEven || allOdd)
				{
					for (int dir : { 0, 2, 4, 6 })
					{
						board[i][j].push_back({ dir,newSpeed,newMass });
					}
				}
				else
				{
					for (int dir : { 1, 3, 5, 7 })
					{
						board[i][j].push_back({ dir,newSpeed,newMass });
					}
				}
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (auto& fireBall : board[i][j])
			{
				answer += fireBall.mass;
			}
		}
	}
	cout << answer;

	return 0;
}
