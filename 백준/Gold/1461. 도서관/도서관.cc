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

	vector<int> left, right;
	int maxDist = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num < 0) left.push_back(abs(num));
		else right.push_back(num);
		maxDist = max(maxDist, abs(num));
	}
	sort(left.rbegin(), left.rend());
	sort(right.rbegin(), right.rend());
	// 39 37 29 28 6
	// 11 2

	// 39 * 2 + 29* 2
	// 11*2 6*2

	int ans = 0;
	for (int i = 0; i < left.size(); i += m) ans += left[i]*2;
	for (int i = 0; i < right.size(); i += m) ans += right[i]*2;

	ans -= maxDist;
	cout << ans;
	return 0;
}
