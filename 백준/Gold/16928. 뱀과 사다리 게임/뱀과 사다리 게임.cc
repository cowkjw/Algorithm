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
using namespace std;

int n, m;
bool vis[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	unordered_map<int, int> sa, sn;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		sa[x] = y;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		sn[x] = y;
	}

	queue<pair<int,int>> q;
	q.push({1,0});
	vis[1] = true;
	int ans = 0;
	while (!q.empty())
	{
		int cur = q.front().first;
		int move = q.front().second;
		q.pop();

		if (cur == 100)
		{
			cout << move;
			return 0;
		}

		for (int i = 1; i <= 6; i++)
		{
			int nextPos = i + cur;

			if (nextPos > 100 || vis[nextPos]) continue;

			if (sa.count(nextPos)) nextPos = sa[nextPos];
			if (sn.count(nextPos)) nextPos = sn[nextPos];

			if (!vis[nextPos])
			{
				vis[nextPos] = true;
				q.push({nextPos, move + 1});
			}
		
		}
	}
	return 0;
}
