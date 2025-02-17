#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <numeric>
using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

int dp[1000001];
int main()
{
	int n;
	cin >> n;

	dp[0] = 1; // 1
	dp[1] = 2; // 00 11
	dp[2] = 3; // 001 100 111

	for (int i = 3; i < n; i++)
	{
		dp[i] = (dp[i -2]+dp[i - 1]) % 15746;
	}
	cout << dp[n - 1] % 15746;
	return 0;
}
