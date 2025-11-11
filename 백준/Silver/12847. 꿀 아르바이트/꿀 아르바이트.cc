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

	vector<int>vec(n+1);
	vector<ll> prefix(n+1);
	for (int i = 1; i <= n; i++) 
	{
		cin >> vec[i];
		prefix[i] = prefix[i - 1] + vec[i];
	}
	// 현재 날짜의 값은 n-m전의 날짜를 뺀 거
	ll ans = 0;
	for (int i = m; i <= n; i++)
	{
		ll val = prefix[i] - prefix[i - m];

		ans = max(val, ans);
	}
	cout << ans;
	return 0;
}
