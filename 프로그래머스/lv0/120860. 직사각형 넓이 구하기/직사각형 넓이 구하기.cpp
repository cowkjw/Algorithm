#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int bigX = -257;
    int smallX = 257;
    int bigY = -257;
    int smallY = 257;
    
    for(const auto& dot : dots)
    {
        bigX = max(bigX,dot[0]);
        smallX = min(smallX,dot[0]);
        bigY = max(bigY,dot[1]);
        smallY = min(smallY,dot[1]);
    }
        
    
    return (bigX-smallX)*(bigY-smallY);
}