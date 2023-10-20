#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 987654321
int n, s;
vector<int> graph[51];
int vis[51];
int ret = -1;
void dfs(int start,int cnt)
{
	vis[start] = 1;
	if (cnt==2)
	{
		return;
	}

	for (int i = 0; i < graph[start].size(); i++)
	{
		dfs(graph[start][i], cnt + 1);
	}
}

void Init()
{
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'Y')
			{
				graph[i + 1].push_back(j + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		Init();
		dfs(i,0);

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) cnt++;
		}
		ret = max(cnt, ret);
	}
	cout << ret-1;
	return 0;
}
