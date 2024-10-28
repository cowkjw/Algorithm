#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n;
struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};


int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;

	priority_queue <pair<int, int>, vector<pair<int, int>>,comp> pq;
	while (n--)
	{
		int x;
		cin >> x;
		if (!x)
		{
			if (!pq.empty())
			{
				cout << pq.top().second << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			pq.push({abs(x),x});
		}
	}
	return 0;
}