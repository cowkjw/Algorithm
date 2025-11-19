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

int answer;
vector<int> tree[200001];
int col[200001];

void DFS(int cur, int prev)
{
	for (auto next : tree[cur])
	{
		if (next == prev) continue;
		if (col[cur] != col[next]) answer++;
		DFS(next, cur);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> col[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	answer = col[1] ? 1: 0;
	DFS(1, 0);

	cout << answer;
	return 0;
}
