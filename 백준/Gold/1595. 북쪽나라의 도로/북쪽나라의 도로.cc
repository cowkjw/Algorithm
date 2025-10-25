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

vector<pii> tree[10001];
int maxDist = 0;
int maxNode = 0;
int vis[10001];

void DFS(int node,int dist)
{
	vis[node] = 1;

	if (dist > maxDist)
	{
		maxDist = dist;
		maxNode = node;
	}

	for (auto& next : tree[node])
	{
		if (vis[next.first]) continue;
		DFS(next.first, dist + next.second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin>>n>>m>>k)
	{
		tree[n].push_back({ m,k });
		tree[m].push_back({ n,k });
	}
	DFS(1,0);

	fill(vis, vis + 10001, 0);
	maxDist = 0;
	DFS(maxNode, 0);
	cout << maxDist << "\n";


	return 0;
}