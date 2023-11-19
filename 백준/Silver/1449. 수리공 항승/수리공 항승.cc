#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int n, l;
vector<int> v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> l;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int pos;
		cin >> pos;
		pq.push(-pos);
	}
	l--;
	int ret = 0;
	while (!pq.empty())
	{
		int cur = -pq.top();
		pq.pop();
		while (!pq.empty() && abs(cur - (-pq.top())) <= l)
		{
			pq.pop();
		}
		ret++;
	}

	cout << ret;

	return 0;
}
