#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int v, e;
int parent[100001];

vector < pair<int, pair<int, int>>> road;
int findParent(int x) {

	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}


void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;

	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}
	
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		road.push_back({ c,{a,b} });
	}

	sort(road.begin(), road.end());
	int ans = 0;
	int last = 0;
	for (int i = 0; i < road.size(); i++)
	{
		int cost = road[i].first;
		int a = road[i].second.first;
		int b = road[i].second.second;
		if (findParent(a) != findParent(b))
		{
			unionParent(a, b);
			ans += cost;
			last = cost;
		}
	}

	cout << ans-last;// 분할을 위해 마지막 제일 큰 비용이 드는 도시 마이너스
}





