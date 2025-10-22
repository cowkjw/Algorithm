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

int parent[30001];
int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}


struct Edge
{
	int u, v, w;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int start, end;
	cin >> n>>start>>end >> m;
	vector<Edge> edges;
	vector<ll> money(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a,b,c });
	}

	for (int i = 0; i < n; i++)
	{
		cin >> money[i];
	}


	vector<ll> dist(n + 1, -LL_INF);
	dist[start]  =  money[start];
	for (int i = 1; i <= n - 1; i++)
	{
		for (auto& e : edges)
		{
			if (dist[e.u] != -LL_INF && dist[e.v] < dist[e.u] - e.w + money[e.v])
				dist[e.v] = dist[e.u] - e.w + money[e.v];
		}
	}

	// 돈을 계속 벌 수 있으면
	vector<int> nodes;
	for (auto& e : edges)
	{
		if (dist[e.u] != -LL_INF && dist[e.v] < dist[e.u] - e.w + money[e.v])
		{
			nodes.push_back(e.v);
		}
	}
	// nodes에서 end로 갈 수 있는지 확인
	vector<int> visited(n + 1, 0);
	queue<int> q;
	for (auto node : nodes)
	{
		visited[node] = 1;
		q.push(node);
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (auto& e : edges)
		{
			if (e.u == cur && visited[e.v] == 0)
			{
				visited[e.v] = 1;
				q.push(e.v);
			}
		}
	}
	if (visited[end])
	{
		cout << "Gee";
		return 0;
	}

	if (dist[end] == -LL_INF)
	{
		cout << "gg";
		return 0;
	}
	cout << dist[end];


	return 0;
}