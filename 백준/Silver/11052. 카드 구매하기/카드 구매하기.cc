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

int dp[1001];
int main()
{
	int n;
	cin >> n;

	vector<int> vec(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}
	// i번째는 i개 

	// 가격/i를 하면 개당 가격이 나옴
	// 이전까지 구매한거, 현재 구매한 거로 구분??
	// dp를 [n]까지 1000 * 1000 = 1000000 번
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=i; j++)
		{
			// 현재 개수에서 최고 가격은
			// 현재까지만 두거나 이전의 것들에서 현재까지의 가격을 더한거 중에 갱신
			dp[i] = max(dp[i], dp[i - j]+vec[j]);
		}
	}
	cout << dp[n];
	return 0;
}
