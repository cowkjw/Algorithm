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

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };


int n, m,r;

vector<int> graph[100001];
int vis[100001];
int cnt = 0;
void DFS(int node)
{

	if (vis[node])
	{
		return;
	}

	vis[node] = ++cnt;

	for (auto next : graph[node])
	{
		DFS(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].rbegin(), graph[i].rend());
	}

	DFS(r);
	for (int i = 1; i <= n; i++)
	{
		cout << vis[i] << '\n';
	}

	return 0;
}
