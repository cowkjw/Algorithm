#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<ll,vector<ll>,greater<ll>> pq;
	cin >> n >> m;

	ll ans = 0;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		
		vec.push_back(ele);	
	}
	sort(vec.rbegin(), vec.rend());

	for (int i = 0; i < n; i++)
	{
		auto ele = vec[i];

		if (pq.size() < m)
		{
			pq.push(ele);
		}
		else
		{
			ll cur = pq.top();
			pq.pop();
			pq.push(ele + cur);
		}
	}
	while (!pq.empty())
	{
		ans = max(pq.top(),ans);
		pq.pop();
	}
	cout << ans;
	return 0;
}
