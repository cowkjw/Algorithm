#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

bool vis[101][101];
const vector<pair<int, int>> delta{ {1,0} ,{-1,0} ,{0,1} ,{0,-1} };


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int size = maps.size();
    
    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<maps[i].size();j++)
        {
            if(!vis[i][j]&&isdigit(maps[i][j]))
            {
                int cnt = 0;
                queue<pair<int,int>> q;
                
                q.push({i,j});
                vis[i][j] = true;
                cnt+=(maps[i][j]-'0');
                
                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    
                    for(const auto& dir : delta)
                    {
                        int nx = dir.first + cur.first;
                        int ny = dir.second + cur.second;
                        
                        if (nx < 0 || nx >= size || ny < 0 || ny >= maps[i].size()) continue;
                        if(vis[nx][ny]) continue;
                        
                        if(isdigit(maps[nx][ny]))
                        {
                            q.push({nx,ny});
                            vis[nx][ny]  = true;
                            cnt += (maps[nx][ny]-'0');
                        }
                       
                    }
                }
                answer.push_back(cnt);
            }
        }
    }
    
    if(answer.empty()) return vector<int>{-1};
    sort(answer.begin(),answer.end());
    
    return answer;
}