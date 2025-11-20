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

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
vector<string> board;
int vis[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<pair<ll, ll>> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i].first>>arr[i].second;
	ll total = 0;
	for (auto& [x, y] : arr)
		total += y;
	sort(arr.begin(), arr.end());
	
	ll sum = 0, ans = 0;
	for (auto& [pos, person] : arr)
	{
		sum += person;

		if (sum >= ((total + 1) / 2))
		{
			ans = pos;
			break;
		}
	}
	cout << ans;
	
	return 0;
}
