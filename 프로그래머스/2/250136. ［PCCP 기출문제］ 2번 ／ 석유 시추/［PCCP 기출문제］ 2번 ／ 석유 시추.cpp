#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

int arr[501];
int vis[501][501];
const int dx[4] {1,0,-1,0};
const int dy[4] {0,1,0,-1};

int solution(vector<vector<int>> land) {
    int answer = 0;
    int row = land.size();
    int col = land[0].size();
    
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
       
        if(land[i][j]&&!vis[i][j])
        {
            queue<pair<int,int>> q;
            set<int> s;
            int cnt = 0;
            q.push({i,j});
            vis[i][j] = 1;
            while(!q.empty())
            {
                int x,y;
                tie(x,y) = q.front();
                q.pop();
                s.insert(y);
                cnt++;
                for(int dir = 0;dir<4;dir++)
                {
                    int nx = dx[dir]+x;
                    int ny = dy[dir]+y;
                    
                    if(nx<0||ny<0||nx>=row||ny>=col
                       ||vis[nx][ny]
                       ||land[nx][ny]==0) continue;
                    
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
             for(auto idx : s)
            {
                arr[idx]+=cnt;
            }
        }
           
        }
    }
    
    sort(arr,arr+501);
    
    return arr[500];
}