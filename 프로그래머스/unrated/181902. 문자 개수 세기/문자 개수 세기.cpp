#include <string>
#include <vector>
using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52,0);
    for(const auto& ch : my_string)
    {
        if(ch>='a')
        {
            answer[(ch-'a')+26]++;
        } 
        else
        {
            answer[ch-'A']++;
        }
            
    }
    return answer;
}