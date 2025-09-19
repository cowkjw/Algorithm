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


using ll = long long;

int n, m;
vector<int> graph[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<int> q;
	q.push(1);

	vector<int> dist(n + 1, -1);
	dist[1] = 0;
	int ans = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : graph[cur])
		{
			if (dist[nxt] == -1)
			{
				dist[nxt] = dist[cur] + 1;
			if (dist[nxt] <= 2)
				ans++;
				q.push(nxt);
			}
		}
	}
	cout << ans;
    return 0;
}