#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };


int n;
int parent[1001];
struct Edge
{
	int u, v, cost;
	bool operator<(const Edge& other) const
	{
		return cost < other.cost;
	}
};

int Find(int u)
{
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
	u = Find(u);
	v = Find(v);
	if (u != v)
		parent[u] = v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	vector<Edge> edges;
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		for (int j = 0; j < n; j++)
		{
			int cost;
			cin >> cost;
			if (i != j)
				edges.push_back({ i,j,cost });
		}
	}

	sort(edges.begin(), edges.end());
	ll ans = 0;
	for (const auto& e : edges)
	{
		if (Find(e.u) != Find(e.v))
		{
			Union(e.u, e.v);
			ans += e.cost;
		}
	}
	cout << ans;


	return 0;
}
