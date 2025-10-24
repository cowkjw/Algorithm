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

vector<int> archeres;
int board[16][16];

int Simul()
{
	int ret = 0;

	int tempBoard[16][16];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tempBoard[i][j] = board[i][j];
		}
	}
	for (int turn = 0; turn < n; turn++)
	{
		vector<pii> targets;

		for (int arch : archeres)
		{
			int minDist = INF;
			pii target = { -1,-1 };
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (tempBoard[i][j] == 1)
					{
						int dist = abs(n - i) + abs(arch - j); // 거리 
						if (dist <= d) // 범위 안에 있는지
						{
							if (dist < minDist) // 새로운 타겟
							{
								minDist = dist;
								target = { i,j };
							}
							else if (dist == minDist) // 같은 거리면 왼쪽 우선
							{
								if (j < target.second)
								{
									target = { i,j };
								}
							}
						}

					}
				}
			}
			if (target.first != -1)
			{
				targets.push_back(target);
			}
		}
		for (auto t : targets)
		{
			if (tempBoard[t.first][t.second] == 1)
			{
				tempBoard[t.first][t.second] = 0;
				ret++;
			}
		}
		for (int i = n - 1; i > 0; i--)
		{
			for (int j = 0; j < m; j++)
			{
				tempBoard[i][j] = tempBoard[i - 1][j];
			}
		}

		for (int j = 0; j < m; j++)
			tempBoard[0][j] = 0;
	}

	return ret;
}
int ans = 0;
void DFS(int pos)
{
	if (archeres.size() == 3) // 3명 고름
	{
		ans = max(ans, Simul());
		return;
	}
	for (int i = pos; i < m; i++)
	{

		archeres.push_back(i);
		DFS(i + 1);
		archeres.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	DFS(0); // 0부터 m-1까지 조합
	cout << ans;
	return 0;
}
