#include <bits/stdc++.h>
using namespace std;

int graph[1002][1002];
bool vis[1002];
int N, M, V;
void DFS(int vertex)
{

	vis[vertex] = true;
	cout << vertex << " ";


	for (int i = 1; i <= N; i++)
	{
		if (vis[i] == true || graph[vertex][i] == 0)
			continue;
		DFS(i);
	}

}

void BFS(int vertex)
{
	queue<int> q;

	vis[vertex] = true;
	q.push(vertex);
	while (!q.empty())
	{
		int temp = q.front();
		cout << temp << " ";
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (graph[temp][i] != 1 || vis[i]) continue;

			q.push(i);
			vis[i] = true;
		}

	}


}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> V;


	for (int i = 0; i < M; i++)
	{
		int start, dest;

		cin >> start >> dest;

		graph[start][dest] = graph[dest][start] = 1;
	}
	DFS(V);
	cout << "\n";
	fill(vis, vis + N + 1, false);
	BFS(V);

	return 0;

}

