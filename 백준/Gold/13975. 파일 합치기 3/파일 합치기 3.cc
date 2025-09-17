#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321



int n, t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		long long ans = 0;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq; // 최소 힙
		for (int i = 0; i < n; i++)
		{
			long long a;
			cin >> a;
			pq.push(a);
		}
		
		while (pq.size() > 1)
		{
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			ans += (a + b);
			pq.push(a + b);
		}
	
		cout << ans << "\n";
	}
	return 0;
}