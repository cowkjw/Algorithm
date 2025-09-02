#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321

long long dp[101][10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int d = 1; d <= 9; d++) 
	{
		dp[1][d] = 1;
	}

	int n;
	cin >> n;
	// 1의 자리는 9개
	// 2의 자리는 17개
	// 10  12  2개
	// 21  23  // 2개
	// 32  34  // 2개
	// 43  45  // 2개
	// 54  56 // 2개
	// 65 67 // 2개
	// 76  78  // 2개
	// 87 89 // 2개
	// 98   // 1개


	// 3자리에서 1의 자리수는 9개
	// 3자리에서 10의 자리수는 17개
	// 101 121 123 3개
	// 210 212 232 234 4개
	// 321 323 343 345 4개
	// 432 434 454 456 4개
	// 543 545 565 567 4개
	// 654 656 676 678 4개
	// 765 767 787 789 4개
	// 876 878 898 3개
	// 987 989 2개
	// 3의 자리수는 
	for (int len = 2; len <= n; len++) 
	{
		for (int d = 0; d <= 9; d++) 
		{
			if (d > 0) dp[len][d] += dp[len - 1][d - 1]; // 0보다 크면 지금 자리수는 이전 자리수에서 d-1이 올 수 있음 // 9라면 이전 자리수는 8밖에 못오니까 그냥 -1
			if (d < 9) dp[len][d] += dp[len - 1][d + 1]; // 9보다 작으면 지금 자리수는 이전 자리수에서 d+1이 올 수 있음 (0은 그냥 무조건 전에 자리가 0보다 커야함)
			dp[len][d] %= 1000000000; // 이건 그냥 나머지 처리
		}
	}
	long long ans = 0;
	for (int d = 0; d <= 9; d++) 
	{
		ans = (ans + dp[n][d]) % 1000000000; // n자리수에서 0~9까지 더하기
	}

	cout << ans << "\n";
	return 0;
}