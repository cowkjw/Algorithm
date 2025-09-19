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

int n, k, m;


vector<int> tree[501];
int visited[501];

pair<int, int> dfs(int u) 
{
	visited[u] = 1;
	int V = 1; // 정점 개수
	int E = 0; // 간선 개수
	for (int v : tree[u])
	{
		E++; // 간선 개수 증가
		if (!visited[v]) 
		{
			auto [v2, e2] = dfs(v); // 재귀적으로 방문
			V += v2; // 정점 개수 누적
			E += e2; // 간선 개수 누적
		}
	}
	return { V,E };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v, e;
	int t = 1;
	while (cin >> v >> e)
	{
		if (v == 0 && e == 0) break;
		for (int i = 1; i <= v; i++)
			tree[i].clear();
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			tree[a].push_back(b); // 양방향 처리
			tree[b].push_back(a);
		}

		fill(visited, visited + v + 1, 0);
		int ans = 0;

		for (int i = 1; i <= v; i++)
		{
			if (!visited[i])
			{
				auto [V, E] = dfs(i);
				if (E / 2 == V - 1)  // 양방향 그래프에서 간선의 개수는 2배로 세어지므로 E/2
					ans++;
			}
		}
		cout << "Case " << t++ << ": ";
		if (ans == 0) cout << "No trees.\n";
		else if (ans == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << ans << " trees.\n";
	}
    return 0;
}