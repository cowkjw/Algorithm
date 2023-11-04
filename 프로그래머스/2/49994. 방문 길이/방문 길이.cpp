#include <string>

using namespace std;

int vis[11][11][11][11];
int solution(string dirs) {
    int answer = 0;

    int n = 11, m = 11;
    pair<int, int> pos = { 5,5 };
    for (int i = 0; i < dirs.size(); i++)
    {
        char dir = dirs[i];
        int x = pos.second, y = pos.first;
        int nx = x, ny = y;
        if (dir == 'D')
        {
            ny = pos.first + 1;
            nx = pos.second;
        }
        else if (dir == 'U')
        {
            ny = pos.first - 1;
            nx = pos.second;
        }
        else if (dir == 'L')
        {
            ny = pos.first;
            nx = pos.second - 1;
        }
        else if (dir == 'R')
        {
            ny = pos.first;
            nx = pos.second + 1;
        }

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (!vis[y][x][ny][nx] && !vis[ny][nx][y][x]) answer++, vis[y][x][ny][nx] = vis[ny][nx][y][x] = 1;
        pos = { ny,nx };
    }

    return answer;
}