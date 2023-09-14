#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
priority_queue<pair<int,int>> pq;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ret = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		pq.push({ -a,b });
    }

	while (!pq.empty())
	{
		if (-pq.top().first > ret)
		{
			ret = -pq.top().first + pq.top().second;
		}
		else
		{
			ret += pq.top().second;
		}
		pq.pop();
	}
	cout << ret;
	return 0;
}