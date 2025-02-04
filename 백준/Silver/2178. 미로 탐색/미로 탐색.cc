
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };
int dist[10][10];
bool vis[10][10];
int seq[10][10];
int main()
{

    int n, m;
    cin >> n >> m;
    
    vector<string> vec(n);
    vector<vector<int>> dist(n, vector<int>(m,INF));

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }


    queue<pair<int, int>> q;

    q.push({ 0,0 });
    dist[0][0] = 1;

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            int nCost = dist[x][y] + 1;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vec[nx][ny] == '0') continue;

            if (nCost < dist[nx][ny])
            {
                dist[nx][ny] = nCost;
                q.push({ nx,ny });
            }
        }
    }

    cout << dist[n-1][m-1];
}