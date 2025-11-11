#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dy[]{0,0,1,-1};
const int dx[]{1,-1,0,0};
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // 시작 사각형 구하기
    // 현재 보다 도착지점이 더 큰 경우 줄여나가기
    // 현재 사각형 범위를 넘어선다면 작은 사각형이나 큰 사각형으로 넘어가기
    // 나는 항상 사각형의 바깥에 있음
    // 아니면 걍 사각형의 정보들로 보드판 만들기?
   int maxX = 0, maxY = 0;
    int minX = 102, minY = 102;
    
    for(const auto& vec : rectangle)
    {
        minX = min(minX, vec[0] * 2);
        minY = min(minY, vec[1] * 2);
        maxX = max(maxX, vec[2] * 2);
        maxY = max(maxY, vec[3] * 2);
    }
    
    vector<vector<int>> board(maxY+1, vector<int>(maxX+1, 0));
    vector<vector<int>> dist(maxY+1, vector<int>(maxX+1, -1));
    

    for(const auto& vec : rectangle)
    {
        for(int y = vec[1] * 2; y <= vec[3] * 2; y++)
        {
            for(int x = vec[0] * 2; x <= vec[2] * 2; x++)
            {
                board[y][x] = 1;
            }
        }
    }
    
    
    for(const auto& vec : rectangle)
    {
        for(int y = vec[1] * 2 + 1; y < vec[3] * 2; y++)
        {
            for(int x = vec[0] * 2 + 1; x < vec[2] * 2; x++)
            {
                board[y][x] = 0;
            }
        }
    }
    
    queue<pair<int,int>> q;
    q.push({characterY * 2, characterX * 2});
    dist[characterY * 2][characterX * 2] = 0;
    
    while(!q.empty())
    {
        auto [y,x] = q.front();
        q.pop();
        
        if(y == itemY * 2 && x == itemX * 2) break;
        
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;
            if(nx < minX || ny < minY || ny > maxY || nx > maxX) continue;
            if(board[ny][nx] == 0) continue;
            if(dist[ny][nx] != -1) continue;
            
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    answer = dist[itemY * 2][itemX * 2] / 2;
    return answer;
}