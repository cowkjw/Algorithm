#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pq.push(-num);
	}
	int ans = 0;

	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	while (!pq.empty())
	{
		auto a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();
		if (!pq.empty())
		{
			pq.push(-(a + b));
		}
		ans += a + b;
	}
	cout << ans;

}