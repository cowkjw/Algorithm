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
const int MOD = 1e9 + 9;
int n, m, d;

ll dp[100001][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int t;
	cin >> t;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1; // 1+ 2, 2+1 , 3

	for (int i = 4; i <= 100000; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%MOD; // 현재에 1을 쓰려면 1을 뺀 전의 수에 2와 3을 사용했어야함
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3])%MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2])%MOD;
	}

	while (t--)
	{
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3])%MOD<<"\n";
	}

	return 0;
}
