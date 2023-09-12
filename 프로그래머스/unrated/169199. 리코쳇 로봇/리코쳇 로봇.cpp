#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int vis[101][101];
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n, m;
pair<int, int> s;
pair<int, int> e;
int answer = 1e9;
void go(pair<int, int> s, vector<string> board)
{
    queue<pair<pair<int, int>,int>>q;
    q.push({ s,1 });
    vis[s.first][s.second] = 1;
    while (!q.empty())
    {
        int x, y, cost;
        x = q.front().first.first;
        y = q.front().first.second;
        cost = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            while (true)
            {
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'D')
                {
                    break;
                }
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];
            if (vis[nx][ny]) continue;
            
            if(board[nx][ny]=='G') vis[nx][ny] = min(cost,vis[nx][ny]);
            vis[nx][ny] = cost;
            q.push({ { nx,ny }, cost + 1 });
        }
    }
}
int solution(vector<string> board) {

    n = board.size();
    m = board[0].size();

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R') s = { i,j };
            else if (board[i][j] == 'G') e = { i,j };
        }
    }

    go(s, board);

    return vis[e.first][e.second] == 0 ? -1 :vis[e.first][e.second] ;
}