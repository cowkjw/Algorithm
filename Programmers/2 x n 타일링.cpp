#include <string>
#include <vector>
#define mod 1000000007
using namespace std;


int solution(int n) {
    int answer = 0;
    vector<long long> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    answer = dp[n];

    return answer;
}