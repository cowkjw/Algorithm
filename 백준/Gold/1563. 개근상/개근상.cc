#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
#define MOD 1000000
using namespace std;

int n, m;
long long dp[1001][2][3]; // 일 , 지각, 결석


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	dp[1][0][0] = 1;
	dp[1][1][0] = 1;
	dp[1][0][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // 출석
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
        // 결석 1번
        dp[i][0][1] = dp[i - 1][0][0] % MOD;
        // 결석 2번
        dp[i][0][2] = dp[i - 1][0][1] % MOD;
        // 지각 1번
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        // 지각 1번 결석 1번
        dp[i][1][1] = dp[i - 1][1][0] % MOD;
        // 지각 1번 결석 2번
        dp[i][1][2] = dp[i - 1][1][1] % MOD;
    }


    long long result = 0;
    for (int j = 0; j < 3; ++j) { // 지각 횟수 0~2
        for (int k = 0; k < 2; ++k) { // 결석 연속 횟수 0~2 (3회 결석은 불가능)
            result = (result + dp[n][k][j]) % MOD;
        }
    }

    cout << result;
	return 0;
}