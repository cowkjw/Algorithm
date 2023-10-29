#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answer;
int vis[10001];
bool dfs(int cnt, string start,vector<vector<string>>& tickets)
{
    if(cnt==tickets.size()) // 깊이 탐색으로 모든 티켓 소모
    {
        return true; // 소모 완료
    }
    
    for(int i = 0;i<tickets.size();i++)
    {   
        if(vis[i]) continue; // 이미 방문한 곳
        if(start==tickets[i][0])// 출발지 동일하고 방문 안한 곳
        {   
            vis[i] = 1; // 방문 처리
            answer.push_back(tickets[i][1]); // 일단 방문으로 처리
            bool connect = dfs(cnt+1,tickets[i][1],tickets); // 연결이 되는지
            if(connect) return true; // 연결이 되었음
            answer.pop_back(); // 연결이 안되어있어서 출발지에서 뺌
            vis[i] = 0; // 출발 안했으니 다시 뺌
        }
   
    }
    return false; // 탐색 후 모든 티켓을 사용하지 못함
}
vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(),tickets.end()); // 알파벳 순서
    answer.push_back("ICN"); // 인천 출발
    dfs(0,"ICN",tickets); // 
    return answer;
}