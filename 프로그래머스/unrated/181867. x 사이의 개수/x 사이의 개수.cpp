#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int cnt = 0;
    for(const auto ch : myString)
    {
        if(ch=='x')
        {
            answer.push_back(cnt);
            cnt = 0;
            continue;
        }
        cnt++;
    }
    answer.push_back(cnt);
    return answer;
}