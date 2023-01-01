#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

int n, m, k, x;
int ans;
vector<int> dist(300001, -1); // �Ÿ�üũ
void BFS(const vector<vector<int>>& cities, int start)
{
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < cities[cur].size(); i++) // ���� ���ÿ��� ����Ǿ� �ִ� ���ø�ŭ ��ȸ
		{
			int next = cities[cur][i]; // ���� ����

			if (dist[next] == -1)
			{
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k >> x;

	vector<vector<int>>cities(n + 1); // 0�� ����
	bool flag = false;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cities[s].push_back(e); // �ܹ��� ����
	}

	BFS(cities, x); //ù��°����

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == k)
		{
			cout << i << '\n';
			flag = true;
		}

	}

	if (!flag)
		cout << -1;
	return 0;
}







