#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<utility>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;
#define INF  9223372036854


int n, k;


int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> n >> k;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	while (k--)
	{
		long long x = pq.top();
		pq.pop();
		long long y = pq.top();
		pq.pop();

		for (int i = 0; i < 2; i++)
		{
			pq.push(x + y);
		}
	}

	long long ans = 0;

	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

	cout << ans;

	return 0;
}