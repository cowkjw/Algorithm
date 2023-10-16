#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int m, n;
int indegree[1001]; // n
vector<int> graph[1001]; // m

void topologysort()
{
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		result.push_back(now);

		for (auto i : graph[now])
		{
			indegree[i] -= 1;

			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
	}
    
    if(result.size()==n)
	for (auto i : result)
    {
		cout << i << '\n';
	}
    else cout<<0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int pd;
		cin >> pd;
		int pre;
        cin>> pre;
		for (int j = 1; j < pd; j++)
		{
			int num;
			cin >> num;
            graph[pre].push_back(num);
			indegree[num]++;
            pre = num;
		}
	}

	topologysort();


	return 0;
}
