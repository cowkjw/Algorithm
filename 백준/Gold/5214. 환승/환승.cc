#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321


using ll = long long;

int n,k, m;
vector<int> graph[100001 + 1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> m;

    for (int i = 1; i <= m; i++) 
    {
        int hyperNode = n + i; // 하이퍼튜브 노드 번호
        for (int j = 0; j < k; j++)
        {
            int station;
            cin >> station;
            graph[station].push_back(hyperNode);
            graph[hyperNode].push_back(station);
        }
    }

    vector<int> dist(100001 + 1000, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 1; // 시작역 포함

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            if (dist[nxt] != -1) continue;

            if (nxt > n) // 하이퍼 
            {
                dist[nxt] = dist[cur];
            }
            else
            {
                dist[nxt] = dist[cur] + 1;
            }

            q.push(nxt);
        }
    }
	cout << dist[n] << "\n";
    return 0;
}