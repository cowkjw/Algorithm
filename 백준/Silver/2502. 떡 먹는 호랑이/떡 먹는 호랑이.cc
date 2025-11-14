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

ll dp[31];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;


	//	K = a + b;
	//	K 가 셋째날이라치면
	//
	//		B만 구하면 되는데
	//		A= K-B;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 30; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	ll fn2 = dp[n - 2]; // A의 계수
	ll fn1 = dp[n - 1]; // B의 계수
	for (ll i = 1; i <= 50000; i++)
	{
		ll A = m - i * fn1;
		if (A <= 0) continue;
		if (A % fn2 != 0) continue;

		A /= fn2;
		if (A <= i)
		{
			cout << A << '\n' << i;
			return 0;
		}
	}

	return 0;
}
