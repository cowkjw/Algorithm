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

	cin >> n >> m;

	if (n == m)
	{
		cout << 0;
		return 0;
	}

	vector<int> vec(n);
	vector<int> dist;
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		if (i > 0)
		{
			dist.push_back(vec[i] - vec[i - 1]);
		}
	}
	// 2  2 1  4
	// 1 2 2 4

	sort(dist.begin(), dist.end());

	int rmvCnt = m - 1;
	while (rmvCnt-- > 0 && dist.empty() == false)
	{
		dist.pop_back();
	}
	int ans = 0;
	for (auto d : dist) ans += d;
	cout << ans;
	
	return 0;
}
