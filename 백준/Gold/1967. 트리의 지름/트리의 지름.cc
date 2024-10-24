#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>

#define INF 987654321
#define MOD 1000000
using namespace std;

int n;
vector<pair<int, int>> graph[10001];
int vis[10001];
int maxDist;
int farNode; // 루트 노드에서 가장 먼 노드(가중치 합이 가장 큰 노드)
void Recur(int node,int dist)
{
	vis[node] = 1; // 방문처리
	if (maxDist<dist)
	{
		maxDist = dist;
		farNode = node;
	}
	for (const auto& i : graph[node])
	{
		if (vis[i.first]) continue;
		Recur(i.first,i.second+dist);
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	// 트리는 정렬이 되어있음.
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;


		// 무방향은 양쪽 연결
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	
	}

	// 루트 노드 1에서 가장 가중치 합이 큰 노드( 가장 먼 노드 찾기)
	Recur(1, 0);
	fill(vis, vis + 10001, 0);
	Recur(farNode, 0);
	cout << maxDist;
	return 0;
}