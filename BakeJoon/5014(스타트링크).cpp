#include <bits/stdc++.h>
using namespace std;

bool vis[1000001];
int f, s, g, u, d; // 識 類熱, ⑷營 類熱, 紫雜 類熱, 嬪煎 陛朝 類熱, 嬴楚煎 陛朝 類熱


void BFS()
{

	queue<pair<int, int>> q;
	q.push({ s,0 });
	vis[s] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur.first == g)
		{
			cout << cur.second;
			return;
		}

		if (f >= cur.first + u&&!vis[cur.first + u])
		{
			q.push({ cur.first + u,cur.second + 1 });
			vis[cur.first + u] = true;
		}
		if (1 <= cur.first - d&&!vis[cur.first - d])
		{
			q.push({ cur.first - d,cur.second + 1 });
			vis[cur.first - d] = true;
		}

	}

	cout << "use the stairs";
}
int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	func();

	return 0;

}

