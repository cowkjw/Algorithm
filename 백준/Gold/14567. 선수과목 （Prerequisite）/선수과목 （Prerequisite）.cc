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
int indegree[1001];
vector<int> graph[1001];
int cnt[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (!indegree[i])
		{
			cnt[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (auto& next : graph[cur])
		{
			indegree[next]--;
			cnt[next] = cnt[cur] + 1;
			if (indegree[next] == 0)
			{
				q.push(next);

			}
		}
	}

	for (int i = 1; i <= n; i++) cout << cnt[i] <<" ";


	return 0;
}
