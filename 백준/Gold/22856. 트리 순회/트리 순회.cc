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


struct Node 
{
	int left = -1;
	int right = -1;
	int parent = -1;
};
int n;

vector<Node> tree(100001);
int vis[100001];
int endNode = -1;
int cnt = 0;

void inorder(int node)
{
	if (node == -1) return;
	inorder(tree[node].left);
	endNode = node; // 마지막 방문 노드로 갱신
	inorder(tree[node].right);
}

void DFS(int node)
{
	int left = tree[node].left;
	int right = tree[node].right;
	int parent = tree[node].parent;

	if (left != -1 && !vis[left]) // 왼쪽 자식이 있으면
	{
		vis[left] = 1;
		cnt++;
		DFS(left); 
	}
	else if (right != -1&& !vis[right]) // 오른쪽 자식이 있으면
	{
		vis[right] = 1;
		cnt++;
		DFS(right);
	}
	else if (node == endNode)
		return;
	else // 왼쪽 오른쪽은 못가는데 부모가 있으면
	{
		cnt++;
		DFS(parent);
	}
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].left = b;
		tree[a].right = c;
		if (b != -1)
			tree[b].parent = a;
		if (c != -1)
			tree[c].parent = a;
	}
	inorder(1); // 마지막 노드 찾기
	DFS(1);

	cout << cnt;
	return 0;
}