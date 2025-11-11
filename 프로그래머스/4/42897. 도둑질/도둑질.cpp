#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> dp(money.size()),dp2(money.size());
    // 첫 집 털기
    dp[0] = money[0];
    dp[1] = max(money[0],money[1]); // 2번째 집을 안털거나 털거나
    
    for(int i = 2;i<money.size()-1;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+ money[i]);
    }
    
    // 첫 집 안 털기
    
    dp2[0] = 0;
    dp2[1] = money[1]; 
    
    for(int i = 2;i<money.size();i++)
    {
        dp2[i] = max(dp2[i-1],dp2[i-2] + money[i]);
    }
    answer = max(dp[money.size()-2],dp2[money.size()-1]);
    return answer;
}