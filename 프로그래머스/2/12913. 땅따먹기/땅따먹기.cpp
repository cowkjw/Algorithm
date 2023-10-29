#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for(int i = 1;i<land.size();i++)
    {
        land[i][0] += max(land[i-1][1],max(land[i-1][2],land[i-1][3]));
        land[i][1] += max(land[i-1][0],max(land[i-1][2],land[i-1][3]));
        land[i][2] += max(land[i-1][1],max(land[i-1][0],land[i-1][3]));
        land[i][3] += max(land[i-1][1],max(land[i-1][2],land[i-1][0]));
    }
    
    int size = land.size()-1;
    answer = max(land[size][0],max(land[size][1],max(land[size][2],land[size][3])));
    return answer;
}