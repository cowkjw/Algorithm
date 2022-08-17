#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;


bool vis[100001];
int n, k;

int dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	bool isFirst = false;

	int ansTime = 0;
	while (!pq.empty())
	{

		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		vis[cur] = true;

		int back = cur - 1;
		int front = cur + 1;
		int jump = 2 * cur;

		if (k == cur)
		{

			ansTime = cost;
			return ansTime;
		}




		if (back >= 0 && !vis[back])
		{
			pq.push({ -(cost + 1) ,back });
		}
		if (front <= 100000 && !vis[front])
		{
			pq.push({ -(cost + 1),front });
		}
		if (jump <= 100000 && !vis[jump])
		{
			pq.push({ -cost,jump });
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	int mTime = dijkstra(n);
	 
	cout << mTime << '\n';
}


