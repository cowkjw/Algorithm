#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 987654321
using namespace std;

int dist[100001];
vector<int> graph[100001];
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(const auto& road : roads)
    {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    fill(dist,dist+n+1,INF);
    
        priority_queue<pair<int,int>> pq;
        dist[destination] = 0;
        pq.push({0,destination});
        
        while(!pq.empty())
        {
            int cost = -pq.top().first;
            int cur = pq.top().second;
            
            pq.pop();
            if(dist[cur]<cost) continue;
            
            for(const auto& node : graph[cur])
            {
                int nextCost = cost+1;
                
                if(dist[node]>nextCost)
                {
                    dist[node] = nextCost;
                    pq.push({-nextCost,node});
                }
            }
        }
    for(const int source : sources)
    {
        if(dist[source] == INF) answer.push_back(-1);
        else answer.push_back(dist[source]);
    }
    
    
    
    return answer;
}