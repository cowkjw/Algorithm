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
		graph[v].push_back(u);
	}

	int maxDist = -1;
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		queue<int> q;
		vector<int> vis(n + 1, -1);
		q.push(i);
		vis[i] = 1;
		int cnt = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cnt++;
			for (int nxt : graph[cur])
			{
				if (vis[nxt] == -1)
				{
					vis[nxt] = 1;
					q.push(nxt);
				}
			}
		}
		if (cnt > maxDist)
		{
			maxDist = cnt;
			ans.clear();
			ans.push_back(i);
		}
		else if (cnt == maxDist)
		{
			ans.push_back(i);
		}
	}
	for (int x : ans)
	{
		cout << x << " ";
	}

    return 0;
}