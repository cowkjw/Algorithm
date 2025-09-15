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

int parent[100001];
int Find(int x)
{
	if (parent[x] != x)
	{
		parent[x] = Find(parent[x]);  // 경로 압축
	}
	return parent[x];
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}


int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	int overEdge = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (Find(a) == Find(b))
		{
			overEdge++;
			continue;
		}
		Union(a, b);
	}
	int compCnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Find(i) == i) compCnt++;
	}

	cout << overEdge + (compCnt - 1);
    return 0;
}