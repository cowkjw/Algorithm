#include <string>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;
int vis[101][101];
int sx,sy;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
queue<pair<int,int>> q;
void Init()
{
   for(int i = 0;i<101;i++)
   {
       for(int j = 0;j<101;j++)
           vis[i][j] = 0;
   }
    q = queue<pair<int,int>>();
    
}
int solution(vector<string> maps) {
    int answer =-1;
    
    for(int i = 0;i<maps.size();i++)
    {
        for(int j = 0;j<maps[j].size();j++)
        {
            if(maps[i][j]=='S')
            {
                sx = i;
                sy = j;
            }
        }
    }
    
    int n = maps.size();
    int m = maps[0].size();
    q.push({sx,sy});
    bool lever = false;
    while(!q.empty())
    {
        int x,y ;
        tie(x,y) = q.front();
        q.pop();
        if(lever && 'E' == maps[x][y] )
        {
            answer = vis[x][y];
            break;
        }
        else if(!lever && 'L' == maps[x][y])
        {
            lever = true;
            int time = vis[x][y];
            Init();
            vis[x][y] = time; 
        }
        for(int i = 0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||vis[nx][ny]) continue;
            if(maps[nx][ny]=='X') continue;
            vis[nx][ny] = vis[x][y]+1;
            q.push({nx,ny});
        }
    }
    
    return answer;
}