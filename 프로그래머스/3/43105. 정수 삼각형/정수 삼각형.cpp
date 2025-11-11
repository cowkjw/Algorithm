#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.back().size()));
    
    // dp[0][0] = 7;
    // dp[1][0] = dp[0][0] + tri[1][0];
    // dp[1][1] = dp[0][0] + tri[1][0];
    // dp[2][1] = max(dp[1][0],dp[1][1]) + tri[2][1];
    // 삼각형의 맨 왼쪽과 오른쪽은 올 수 있는게 행의 -1밖에 없다
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 1;i<triangle.size();i++)
    {
        for(int j = 0;j<triangle[i].size();j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if(j == triangle[i].size()-1)
            {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
            }
        }
    }
    for(auto num : dp[triangle.size()-1])
    {
        answer = max(num,answer);
    }
    return answer;
}