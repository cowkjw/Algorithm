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
	int ret = pq.size();
	for (int i = 1; i < v.size(); i++)
	{
		if (-pq.top().first > v[i].first)
		{
			pq.push({ -v[i].second,v[i].first });
			ret = pq.size();
		}
		else
		{
			pq.pop();
			pq.push({ -v[i].second,v[i].first });
		}
	}
	cout << ret;
	return 0;
}
