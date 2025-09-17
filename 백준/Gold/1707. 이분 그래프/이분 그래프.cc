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



int n,t;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> t;
    while (t--) 
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> graph(v + 1);
        for (int i = 0; i < e; i++) 
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> color(v + 1, -1);
        bool isBipartite = true;

        for (int start = 1; start <= v; start++)
        {
			if (color[start] != -1) continue; // 이미 방문한 노드면 패스

            queue<int> q; 
            q.push(start);
            color[start] = 0;

            while (!q.empty() && isBipartite) 
            {
                int cur = q.front(); 
                q.pop();
                for (int nxt : graph[cur])
                {
                    if (color[nxt] == -1)
                    {
						color[nxt] = (color[cur] + 1) % 2; // 다른 색으로 칠하기
                        q.push(nxt);
                    }
					else if (color[nxt] == color[cur])  // 같은 색이면 이분 그래프 아님
                    {
                        isBipartite = false;
                        break;
                    }
                }
            }
        }

        cout << (isBipartite ? "YES\n" : "NO\n");
    }

	return 0;
}