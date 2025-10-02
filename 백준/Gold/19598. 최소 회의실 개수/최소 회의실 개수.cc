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


using ll = long long;

struct Meeting
{
	int start;
	int end;
	bool operator<(const Meeting& other) const
	{
		return start < other.start;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	vector<Meeting> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].start >> v[i].end;
	}
	sort(v.begin(), v.end());

	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		if (!pq.empty() && pq.top() <= v[i].start)
		{
			pq.pop();
		}
		pq.push(v[i].end);
		ans = max(ans, (int)pq.size());
	}
	cout << ans;

    return 0;
}