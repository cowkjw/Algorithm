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

int dp[10001];
int main()
{
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	dp[0] = vec[0];
	dp[1] = dp[0] + vec[1];
	dp[2] = max({ dp[1], vec[0] + vec[2], vec[1] + vec[2] });

	for (int i = 3; i < n; i++)
	{
		// 현재 잔을 마시지 않는 경우, 전전의 잔과 지금 잔을 마시는 경우, 전전전, 전 , 현재
		dp[i] = max({ dp[i - 1], dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i] });
	}
	cout << dp[n - 1];
	return 0;
}
