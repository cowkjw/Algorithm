#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
int ret = INF;
vector<int> v[11];
vector<int> v1, v2;
int arr[11];
bool Check()
{
	if (v1.size() == 0 || v2.size() == 0) return false;
	int vis[11]{ 0, };
	
	queue<int> q;
	q.push(v1[0]);
	vis[v1[0]] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (const auto j : v[cur])
		{
			if (!vis[j] && find(v1.begin(), v1.end(), j) != v1.end())
			{
				vis[j] = 1;
				q.push(j);
			}
		}
	}

	for (int i : v1)
	{
		if (!vis[i]) return false;
	}

	memset(vis, 0, sizeof(vis));

	q.push(v2[0]); 
	vis[v2[0]] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (const auto j : v[cur])
		{
			if (!vis[j] && find(v2.begin(), v2.end(), j) != v2.end())
			{
				vis[j] = 1;
				q.push(j);
			}
		}
	}

	for (int i : v2)
	{
		if (!vis[i]) return false;
	}

	return true;
}

int Diff()
{
	int cnt1, cnt2;
	cnt1 = cnt2 = 0;

	for (int i : v1)
	{
		cnt1 += arr[i];
	}

	for (int i : v2)
	{
		cnt2 += arr[i];
	}

	return abs(cnt2 - cnt1);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;
		arr[i] = cnt;
	}
	for (int j = 1; j <= n; j++)
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			int node;
			cin >> node;
			v[j].push_back(node);
		}
	}

	for (int i = 0; i < (1 << n); i++)
	{
		v1.clear();
		v2.clear();
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				v1.push_back(j+1);
			}
			else
			{
				v2.push_back(j+1);
			}
		}

		if (Check())
		{
			ret = min(Diff(), ret);
		}
	}
	cout << (ret==INF? -1:ret);
	return 0;
}