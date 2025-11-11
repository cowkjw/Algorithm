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

	priority_queue<int, vector<int>, greater<int>> maxHeap;
	priority_queue<int> minHeap;
	cin >> m;
	vector<int> ans;
	for (int i = 1; i <= m; i++)
	{
		cin >> n;

		if (minHeap.empty() || minHeap.top() > n)
		{
			minHeap.push(n);
		}
		else
		{
			maxHeap.push(n);
		}

		if (minHeap.size() < maxHeap.size())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (maxHeap.size() + 1 < minHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		cout << minHeap.top() << "\n";
	}
	return 0;
}
