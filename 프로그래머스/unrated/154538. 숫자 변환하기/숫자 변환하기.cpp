#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dist[1000001];
int solution(int x, int y, int n) {
	queue<int> q;
	fill(dist, dist + 1000001, -1);
	dist[x] = 0;
	q.push(x);

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (auto next : { cur + n,cur * 2,cur * 3 })
		{
			if (next < 0 || next>y) continue;
			if (dist[next] != -1) continue;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
	return dist[y];
}
