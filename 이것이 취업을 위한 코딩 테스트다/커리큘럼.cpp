#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;


int indegree[501];
vector<int> graph[501];
int Time[501];
int n;

void topologySort()
{
	vector<int> res;
	queue<pair<int, int>> q;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			q.push({ i,Time[i] });
	}


	while (!q.empty())
	{
		int cur = q.front().first;
		int t = q.front().second;
		q.pop();
		res.push_back(t);

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int total = t + Time[graph[cur][i]];
			indegree[graph[cur][i]] -= 1;
			if (indegree[graph[cur][i]] == 0)
				q.push({ graph[cur][i],total });
		}
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << i + 1 << "번째 출력" << res[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t;
		int course;
		cin >> t;
		Time[i] = t;
		int cnt = 0;
		while (true)
		{
			cin >> course;
			if (course == -1)
				break;
			graph[course].push_back(i);
			cnt++;
		}
		indegree[i] = cnt;
	}

	topologySort();


}





