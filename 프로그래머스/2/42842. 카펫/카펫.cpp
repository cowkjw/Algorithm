#include <string>
#include <vector>

using namespace std;

bool check()
{
    
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown+yellow;
    for(int i = 3;i<=total/2;i++)
    {
        if((total/i-2)*(i-2)==yellow)
        {
            answer.push_back(total/i);
            answer.push_back(i);
            break;
        }
    }
    return answer;
}