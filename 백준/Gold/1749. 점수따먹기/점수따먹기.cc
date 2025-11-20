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
	vector<vector<int>> prefix(n + 1, vector<int>(m + 1));
	int ans = (int)-1e9;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int num;
			cin >> num;
			prefix[i][j] = num + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= i; k++)
			{
				for (int l = 1; l <= j; l++)
				{
					// k,l ~ i,j
					int sum = prefix[i][j] - prefix[k - 1][j] - prefix[i][l - 1] + prefix[k - 1][l - 1];
					ans = max(sum, ans);
				}
			}
		}
	}

	cout << ans;
	return 0;
}
