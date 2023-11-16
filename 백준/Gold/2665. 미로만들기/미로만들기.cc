#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<string> arr;
int n;
int dist[51][51];
const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,-0 };
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		arr.push_back(str);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) dist[i][j] = INF;
	}

	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, { 0,0 } });
	dist[0][0] = 0;
	int ret = 0;
	while (!pq.empty())
	{
		auto cur = pq.top();
		int cost = -pq.top().first;
		pq.pop();
		int x, y;
		tie(y, x) = cur.second;
		if (n - 1 == x && n - 1 == y) break;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nCost = cost;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (arr[ny][nx] == '0') nCost++;
			if (dist[ny][nx] > nCost)
			{
				dist[ny][nx] = nCost;
				pq.push({ -nCost,{ny,nx} });
			}
		}
	}
	cout << dist[n-1][n-1];

	return 0;
}
