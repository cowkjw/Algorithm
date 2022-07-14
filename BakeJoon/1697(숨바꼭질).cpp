#include <bits/stdc++.h>
using namespace std;


int dist[100002];
int N, K;
int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	fill(dist, dist + 100001, -1);

	dist[N] = 0;
	queue<int>q;
	q.push(N);

	while (dist[K]==-1) // 가장 빠른 시간을 구했을 때 멈춤
	{
		auto cur = q.front();
		q.pop();
		for (int nxt : {cur - 1, cur + 1, 2 * cur})  //{}안에 있는 순으로 nxt 초기화
		{
			if (nxt < 0 || nxt>100000)
				continue;
			if (dist[nxt] != -1)
				continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	
	cout << dist[K];
	return 0;

}

