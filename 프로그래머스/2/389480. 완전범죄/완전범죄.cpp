#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = -1;
    const int INF = 987654321;
    // 흔적 개수가 넘지 않도록 조건
    
    // N번째 물건을 훔칠 때 i만큼의 흔적을 남겼을 때 B가 남기는 흔적의 최소개수
    vector<vector<int>> dp((int)info.size()+1,vector<int>(n+1,INF));
    dp[0][0] = 0; // 아무것도 안 훔침
    // dp[B가 남길 수 있는 증거][i번째 물건]
    for(int i = 1;i<=(int)info.size();++i) // 일단 끝까지 훔치는 거
    {
        int avA = info[i-1][0]; // 이전의 흔적
        int avB = info[i-1][1];
        
        for(int j = 0;j<n;++j) // B가 남길 수 있는 흔적만큼 (최대 120개)
        {
              // B가 i번째 물건을 훔치는 경우
            if(dp[i-1][j] + avB<m)
            {
                // 현재 B의 흔적이 지금이 나은지 아니면 훔치는 게 나은지
              dp[i][j] = min(dp[i][j],dp[i-1][j]+avB);
            }
            // A가 i번째 물건을 훔치는 경우를 처리 ,이전에 A가 훔쳤더라면
             if (j >= avA && dp[i-1][j-avA] != INF) 
             {
                 // A가 현재 물건을 훔칠 경우와 이전에 계산된 방법 중 B의 흔적이 더 적은 방법 선택
                dp[i][j] = min(dp[i][j], dp[i-1][j-avA]);
             }
            
        }
    }
    
    int size = (int)info.size();
     for (int i = 0; i < n; ++i)
     {
        if (dp[size][i] < m) 
        {
            answer = i;
            break;
        }
    }
    return answer;
}