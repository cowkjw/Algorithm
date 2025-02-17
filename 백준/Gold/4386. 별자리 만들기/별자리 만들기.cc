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
#include <numeric>

using namespace std;
#define INF 987654321

int n;
vector<pair<double,double>> coord;

int parent[101];

int Find(int a)
{
	if (parent[a] != a)
	{
		return parent[a] = Find(parent[a]);
	}
	return a;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a > b) parent[b] = a;
	else parent[a] = b;
}

struct Edge 
{
	int u, v;
	double weight;
};

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;

		coord.push_back({ x,y });
	}
	// 좌표들 담고
	// 담은 좌표를 각각 번호를 매겨서
	// 다른 좌표들과의 거리를 두고 정렬 시키기
	// 정렬 시킨 다음에 MST 만든다

	vector<Edge> edges;
	for (int i = 0; i < n; i++) // 노드 번호
	{
		for (int j = i + 1; j < n; j++)
		{
			// 노드를 두고 다른 노드들과의 거리로 두기
			double dist = hypot(coord[i].first - coord[j].first, coord[i].second - coord[j].second);
			edges.push_back({ i + 1,j + 1,dist });
		}
	}

	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
		{
			return a.weight < b.weight;
		});

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	double ans = 0.;
	int edgeCnt = 0;
	for (const auto& e : edges)
	{
		if (Find(e.u) != Find(e.v))
		{
			Union(e.u, e.v);
			ans += e.weight;
			edgeCnt++;
		}

		if (edgeCnt == n - 1) break;
	}

	cout.precision(3);
	cout << ans;
	return 0;
}
