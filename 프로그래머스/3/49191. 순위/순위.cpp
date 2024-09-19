#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> graph(101,vector<int>(101,50000));
    
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            graph[i][j] = ( i==j ? 0 : graph[i][j]);
        }
    }
    
    for(const auto& res : results)
    {
        int win = res[0], los = res[1];
        graph[win][los] = 1;
    }
    
    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j]< 50000 || graph[j][i] < 50000) cnt++;
        }
        
        if(cnt == n) answer++;
    }
    
    return answer;
}