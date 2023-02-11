#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second


using namespace std;
vector<pair<int, int>> del{ {1,0} ,{-1,0} ,{0,1} ,{0,-1} }; 


int n;
int arr[126][126];
int d[126][126];

void dijkstra()
{
	priority_queue<pair<int, pair<int, int>> > pq;

	pq.push({ -arr[0][0],{0,0} });
	d[0][0] = arr[0][0];

	while (!pq.empty()) 
	{ 

		auto dist = -pq.top().first; 
		auto now = pq.top().second;
		pq.pop();
		
		if (d[now.X][now.Y] < dist) continue;

		for (auto dir = 0;dir<4;dir++)
		{
			auto nx = del[dir].X + now.X;
			auto ny = del[dir].Y + now.Y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			auto cost = dist + arr[nx][ny];
			if (cost < d[nx][ny]) 
			{
				d[nx][ny] = cost;
				pq.push({ -cost, {nx,ny } });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		t++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				fill(d[i], d[i] + n, INF);
			}
		}

		dijkstra();

		cout << "Problem "<< t<<": "<< d[n - 1][n - 1] << '\n';
	}

	return 0;
}
