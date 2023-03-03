#include <string>
#include <vector>


using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    auto sizeX = wallpaper.size();
    auto sizeY = wallpaper[0].size();
    
    pair<int,int> maxPos{0,0};
    pair<int,int> minPos{sizeX,sizeY};
    
    for(int x = 0;x<sizeX;x++)
    {
        for(int y = 0;y<sizeY;y++)
        {
            if(wallpaper[x][y]=='#')
            {
                maxPos.first = max(maxPos.first,x);
                maxPos.second = max(maxPos.second,y);
                
                minPos.first = min(minPos.first,x);
                minPos.second = min(minPos.second,y);
            }
        }
    }
    
    answer.push_back(minPos.first);
    answer.push_back(minPos.second);
    answer.push_back(maxPos.first+1);
    answer.push_back(maxPos.second+1);
    
    return answer;
}