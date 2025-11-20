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
	vector<vector<int>> arr(n + 1, vector<int>(m + 1));
	int ans = (int)-1e9;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int top = 1; top <= n; top++)
	{
		vector<int> tmp(m + 1);

		for (int bt = top; bt <= n; bt++)
		{
			for (int col = 1; col <= m; col++)
			{
				tmp[col] += arr[bt][col];
			}

			int best = (int)-1e9;
			int cur = 0;

			for (int col = 1; col <= m; col++)
			{
				cur += tmp[col];

				best = max(best, cur);
				if (cur < 0) cur = 0;
			}

			ans = max(ans, best);
		}
	}

	cout << ans;
	return 0;
}
