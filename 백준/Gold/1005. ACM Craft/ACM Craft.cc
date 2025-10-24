#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hDx[] = { -2,-2,-1,-1,1,1,2,2 };
const int hDy[] = { -1,1,-2,2,-2,2,-1,1 };


int indegree[30001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<int> cost(n + 1);
		vector<vector<int>> adj(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> cost[i];
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			indegree[v]++;
			adj[u].push_back(v);
		}
		cin >> k;
		queue<int> q;

		vector<int> depth(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0)
			{
				depth[i] = cost[i];
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur])
			{
				indegree[nxt]--;
				depth[nxt] = max(depth[nxt], depth[cur] + cost[nxt]);
				if (indegree[nxt] == 0)
				{
					q.push(nxt);
				}
			}
		}
		cout << depth[k] << "\n";
	}

	return 0;
}