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



int finished[100001];
int vis[100001];
vector<pii>v;
int cnt = 0;
void DFS(int node)
{
	vis[node] = 1;
	int next = v[node].second;

	if (!vis[next])
	{
		DFS(next);
	}
	else if (!finished[next]) // 싸이클이 존재
	{
		for (int i = next; i != node; i = v[i].second)
			cnt++;
		cnt++;
	}

	finished[node] = 1; // 탐색 완료
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	while (t--)
	{

		cin >> n;
		v.clear();
		v.resize(n+1);
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i].second;
			v[i].first = i + 1;
		}
		fill(finished, finished + n + 1, 0);
		fill(vis, vis + n + 1, 0);

		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
				DFS(i);
		}
		cout << n - cnt << "\n";
	}

	return 0;
}