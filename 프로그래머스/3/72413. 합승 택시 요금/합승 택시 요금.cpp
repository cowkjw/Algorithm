#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> graph[201];

vector<int> dijkstra(int start, int n)
{
    priority_queue<pair<int,int>> pq;
    vector<int> dis(n+1,20000000);
    pq.push({0,start}); // 비용, 노드
    dis[start] = 0; // 비용
    while(!pq.empty())
    {
        int curCos = -pq.top().first; // 현재 가격
        int curNode = pq.top().second; // 현재 위치
        pq.pop();
        
        for(auto& i : graph[curNode]) // 현재 위치에서 갈 수 있는 곳
        {
            int nextCos = i[1]+ curCos; // 다음으로 갈 때 비용
            int nextNode = i[0]; // 다음 위치
            // 만약 현재 위치에서 다음 지역으로 갈 때 비용이 더 적다면
            if(dis[nextNode]>nextCos) 
            {
                dis[nextNode] = nextCos; // 가격 변경
                
                pq.push({-nextCos,nextNode}); // 현재까지의 가격을 넣고 다음 위치로 이동
            }
        }
    }
    
    return dis;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    
    for(auto& fare : fares) // 그래프 만들기
    {
        int u,v,cos;
        u = fare[0];
        v = fare[1];
        cos = fare[2];
        graph[u].push_back({v,cos});
        graph[v].push_back({u,cos});
    }
    
    vector<int> sStart = dijkstra(s,n);
    vector<int> aStart = dijkstra(a,n);
    vector<int> bStart = dijkstra(b,n);
    
    for(int i = 1;i<=n;i++)
    {
        answer = min(answer,sStart[i]+aStart[i]+bStart[i]);
    }

    return answer;
}