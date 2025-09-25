#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };

struct Island 
{
	ll weight; // 중량 제한
	int  num; //연결된 섬의 번호
	Island(ll w, int n) : weight(w), num(n) {}
	bool operator<(const Island& other) const
	{
		return weight < other.weight;
	}
};

int n, m;
int factoryA, factoryB;
ll maxWeight = 0;
vector<Island> islands[100001];
ll dist[100001]; // 시작점에서 각 섬까지의 최대 중량
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;
		// 양방향
		islands[a].emplace_back(c, b);
		islands[b].emplace_back(c, a);
	}

	cin >> factoryA >> factoryB;

	fill(dist, dist + n + 1, -1);
	priority_queue<Island> pq;
	pq.push({ LLONG_MAX,factoryA });
	dist[factoryA] = LLONG_MAX;
	
	while (!pq.empty())
	{
		int cur = pq.top().num;
		ll weight = pq.top().weight;
		pq.pop();
		if (dist[cur] > weight) continue;
		for (auto& next : islands[cur])
		{
			ll nextWeight = min(weight, next.weight);
			if (dist[next.num] < nextWeight) 
			{
				dist[next.num] = nextWeight;
				pq.push(Island(nextWeight,next.num));
			}
		}
	}
	cout << dist[factoryB] << "\n";

	return 0;
}
