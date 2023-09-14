#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int> pq;
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
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret += v[i].second;
		pq.push(-v[i].second);
		if (pq.size() > v[i].first)
		{
			ret-=-pq.top();
			pq.pop();
		}
	}
	cout << ret;
	return 0;
}