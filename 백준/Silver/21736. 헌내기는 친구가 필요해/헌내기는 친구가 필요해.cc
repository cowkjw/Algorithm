#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };
int dist[10][10];
bool vis[601][601];
int seq[10][10];

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> vec;
    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        vec.push_back(str);
         size_t pos = str.find('I');
        if (pos != string::npos)
        {
            start = { i, static_cast<int>(pos) };
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    int ans = 0;
    while (!q.empty())
    {
        int y,x;
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || ny >= n || nx >= m || vis[ny][nx]||vec[ny][nx]=='X') continue;

            if (vec[ny][nx] == 'P') ans++;

            q.push({ ny,nx });
            vis[ny][nx] = true;
         }

    }

    cout << (ans == 0 ?"TT" : to_string(ans));
return 0;
}