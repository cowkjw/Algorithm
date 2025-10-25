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
#include <sstream>
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

ll parent[100001];
ll Find(ll x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(ll a, ll b)
{
	a = Find(a);
	b = Find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}


vector<tuple<ll, ll, ll>> edges;
int main()
{
	cin >> n >> m;
	ll total = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ w,u,v });
		total += w;
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	ll mst_cost = 0;
	int edge_cnt = 0;

	for (auto [w, u, v] : edges)
	{
		// 사이클이 생기지 않으면 선택
		if (Find(u) != Find(v)) 
		{

			Union(u, v);

			mst_cost += w;
			edge_cnt++;

			if (edge_cnt == n - 1) break;
		}
	}
	if (edge_cnt != n - 1)
	{
		cout << -1 << "\n";
		return 0;
	}
	cout << total - mst_cost << "\n";
	return 0;
}