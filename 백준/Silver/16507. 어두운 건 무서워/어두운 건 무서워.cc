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

	int k;
	cin >> n >> m >> k;
	vector<vector<int>> vec(n+1,vector<int>(m+1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> vec[i][j];
		}
	}
	vector<vector<int>> prefix(n+1,vector<int>(m+1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			prefix[i][j] =  prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + vec[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int sum = prefix[c][d] - prefix[c][b - 1] - prefix[a - 1][d] + prefix[a - 1][b - 1];
		int cnt = (d - b + 1) * (c - a + 1);
		int avg = (sum / cnt);
		cout << avg << '\n';
	}


	return 0;
}
