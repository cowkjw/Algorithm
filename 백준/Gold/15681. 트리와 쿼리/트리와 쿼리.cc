#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
using namespace std;

int n, r, q;

vector<int>graph[100001];
int dp[100001];
bool visited[100001];
void MakeTree(int currentNode)
{
    visited[currentNode] = true;
    dp[currentNode] = 1; // 자기 자신 포함
    for (int node : graph[currentNode]) 
    {
        if (!visited[node]) 
        {
            MakeTree(node); // 자식 노드 탐색
            dp[currentNode] += dp[node]; // 서브트리 크기 추가
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> r >> q;

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    MakeTree(r);

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;

        cout << dp[a] << '\n';
    }
    
    return 0;
}

