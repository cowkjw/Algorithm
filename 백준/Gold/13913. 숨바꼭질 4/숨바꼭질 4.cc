#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

const int MAX = 200000;
int vis[MAX+1];
int Prev[MAX + 1];
vector<int> v;
int n, m;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	vis[n] = 1;
	queue<int> q;
	q.push(n);

	vector<int> v;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == m)
		{
			break;
		}

		for (int next : {cur -1, cur + 1, cur * 2})
		{
			if (0 <= next && next<= MAX)
			{
				if (!vis[next])
				{
					vis[next] = vis[cur] + 1;
					Prev[next] = cur;
					q.push(next);
				}
			}
		}
	}
	cout << vis[m]-1<<"\n";

	for (int i = m; i != n; i = Prev[i])
	{
		v.push_back(i);
	}
	v.push_back(n); 
	reverse(v.begin(), v.end());
	for (int i : v) cout << i << " ";
}