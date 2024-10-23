#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
using namespace std;
int n;
vector<int> tree[100001];
int parent[100001];
void PreOrder(int node,int prev)
{
	parent[node] = prev;// 현재 노드의 부모

	for (const auto child : tree[node])
	{
		if (child == prev) continue;
		PreOrder(child, node);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	PreOrder(1,0);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}
	return 0;
}