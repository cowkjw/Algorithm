#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;


int indegree[32001];
vector<int> graph[32001];
int n, m;

void topologySort()
{
	vector<int> res;
	queue<int> q;


	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}


	while (!q.empty())
	{
		int cur = q.front();

		q.pop();
		res.push_back(cur);

		for (int i = 0; i < graph[cur].size(); i++)
		{
			indegree[graph[cur][i]] -= 1;
			if (indegree[graph[cur][i]] == 0)
				q.push(graph[cur][i]);
		}
	}

	for (int i = 0; i <n; i++)
	{
		cout << res[i] <<" ";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		indegree[b] += 1;
	}

	topologySort();

}






