#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int dist[20001];
bool vis[20001];
vector<int> graph[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(const auto& e : edge)
    {
        int u = e[0], v = e[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    queue<int> q;
    q.push(1);
    vis[1] = true;
    int maxLen = -1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(const auto& next : graph[cur])
        {
            
            if(vis[next]) continue;
            dist[next] = dist[cur]+1;
            maxLen = max(dist[next],maxLen);
            vis[next] = true;
            q.push(next);
        }
    }
    
    answer = count(dist,dist+n+1,maxLen);
    return answer;
}