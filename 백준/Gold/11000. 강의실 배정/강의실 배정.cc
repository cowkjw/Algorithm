#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 987654321
int n;
vector<pair<int, int>> v;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	priority_queue<pair<int, int>>pq;// 끝 시작
	pq.push({ -v[0].second,v[0].first });
	queue<pair<int, int>>q;
	for (int i = 1; i < v.size(); i++)
	{
		q.push({ v[i].first,v[i].second });
	}
	int ret = pq.size();
	while (!pq.empty())
	{
		if (!q.empty())
		{
			if (-pq.top().first > q.front().first)
			{
				pq.push({ -q.front().second,q.front().first });
				ret = pq.size();
				q.pop();
			}
			else
			{
				pq.pop();
				pq.push({ -q.front().second,q.front().first });
				q.pop();
			}
		}
		else
		{
			pq.pop();
		}
	}
	cout << ret;
	return 0;
}
