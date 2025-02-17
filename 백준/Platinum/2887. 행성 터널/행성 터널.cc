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

int n;
int parent[100001];

vector<pair<int,int>> coordX;
vector<pair<int, int>> coordY;
vector<pair<int, int>> coordZ;

int  Find(int  a)
{
	if (parent[a] != a)
	{
		return parent[a] = Find(parent[a]);
	}
	return a;
}

void Union(int  a, int  b)
{
	a = Find(a);
	b = Find(b);

	if (a > b) parent[b] = a;
	else parent[a] = b;
}

struct Edge
{
	int u, v;
	int weight;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		coordX.push_back({ x,i });
		coordY.push_back({ y,i });
		coordZ.push_back({ z,i });
	}

	// 인접 노드를 만들기 위해서 정렬 시킴
	sort(coordX.begin(), coordX.end());
	sort(coordY.begin(), coordY.end());
	sort(coordZ.begin(), coordZ.end());

	vector<Edge> edges;
	// 축 별로 인접한 애들만 연결 시켜서 모든 정점을 구하지 않기 위함
	for (int i = 0; i < n-1; i++) // 노드 번호
	{
		// 인접한 애들끼리만 연결
	  // 원래 노드 번호 가져오기
		int u = coordX[i].second;   // i번째 원소의 원래 노드 번호
		int v = coordX[i + 1].second; // i+1번째 원소의 원래 노드 번호
		int dist = abs(coordX[i].first - coordX[i + 1].first);
		edges.push_back({ u, v, dist });

		u = coordY[i].second;
		v = coordY[i + 1].second;
		dist = abs(coordY[i].first - coordY[i + 1].first);
		edges.push_back({ u, v, dist });

		u = coordZ[i].second;
		v = coordZ[i + 1].second;
		dist = abs(coordZ[i].first - coordZ[i + 1].first);
		edges.push_back({ u, v, dist });
	}

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
		return a.weight < b.weight;
		});

	int ans = 0;
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

	cout << ans;

	return 0;
}