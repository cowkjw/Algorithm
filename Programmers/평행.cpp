#include <string>
#include <vector>

using namespace std;

bool SameGradient(vector<int> dot1, vector<int> dot2, vector<int> dot3, vector<int> dot4)
{
    return double(dot1[1] - dot2[1]) / (dot1[0] - dot2[0]) == double(dot3[1] - dot4[1]) / (dot3[0] - dot4[0]);
}


int solution(vector<vector<int>> dots) {

    if (SameGradient(dots[0], dots[1], dots[2], dots[3]))
    {
        return 1;
    }
    else if (SameGradient(dots[0], dots[2], dots[1], dots[3]))
    {
        return 1;
    }
    else if (SameGradient(dots[0], dots[3], dots[2], dots[3]))
    {
        return 1;
    }

    return 0;
}