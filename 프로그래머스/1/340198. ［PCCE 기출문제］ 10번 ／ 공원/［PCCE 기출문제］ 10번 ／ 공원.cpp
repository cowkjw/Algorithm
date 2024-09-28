#include <string>
#include <vector>

using namespace std;

int sizeX, sizeY;

bool Find_Can_Pos(int sx,int sy, const vector<vector<string>>& park, const int matSize)
{
    int canPosX, canPosY;
    for(int y = 0; y < matSize; y++)
    {
        for(int x = 0; x < matSize; x++)
        {
            canPosX = sx + x;
            canPosY = sy + y;
            
            if(canPosX >= sizeX || canPosX < 0 || canPosY >= sizeY ||  canPosY <0
               || park[canPosY][canPosX] != "-1" )
            {
                return false;
            }
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    sizeX = park[0].size();
    sizeY = park.size();
    // 가로 세로 -1씩 찾아 나가기
    for(const auto mat : mats)
    {
        for(int y = 0; y < sizeY ; y++)
        {
            for(int x = 0 ; x < sizeX ; x++)
            {
                if(Find_Can_Pos(x,y,park,mat))
                {
                    answer = max(mat,answer);
                }
            }
            
        }
    }
    return answer;
}