#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    
    for(const auto& str : dic)
    {
        bool flag = false;
        for(const auto c : spell)
        {
            if(str.find(c)==-1)
            {
                flag = true;
            }
        }
        if(!flag)
            answer++;
    }
    
    return answer==0? 2:1;
}