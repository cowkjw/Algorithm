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

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
vector<string> board;
int vis[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j]) continue;

			queue<pii> q;
			q.push({ i,j });
			vis[i][j] = 1;
			char target = board[i][j];


			int cnt = 1;
			while (!q.empty())
			{
				auto [y, x] = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny < 0 || nx < 0 || ny >= m || nx >= n || vis[ny][nx]) continue;
					if (target == board[ny][nx])
					{
						cnt++;
						vis[ny][nx] = 1;
						q.push({ ny,nx });
					}
				}
			}
			if (target == 'W')
			{
				ans2 += cnt * cnt;
			}
			else
			{
				ans1 += cnt * cnt;
			}

		}
	}
	cout << ans2 << " " << ans1;
	return 0;
}
