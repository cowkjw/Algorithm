#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
vector<pair<int, int>> graph[51];
int d[51];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;

    pq.push({ 0,start });
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist)
            continue;
        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = dist + graph[now][i].second;

            if (cost < d[graph[now][i].first])
            {
                d[graph[now][i].first] = cost;
                pq.push({ -cost,graph[now][i].first });
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < road.size(); i++)
    {
        graph[road[i][0]].push_back({ road[i][1],road[i][2] });
        graph[road[i][1]].push_back({ road[i][0],road[i][2] });
    }

    fill(d, d + 51, INF);

    dijkstra(1);

    for (auto i : d)
    {
        if (i <= K)
        {
            answer++;
        }

    }

    return answer;
}