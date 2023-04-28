#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(const auto& str : intStrs)
    {
        auto num = stoi(str.substr(s,l));
       if(k<num)
       {
           answer.push_back(num);
       }
    }
    return answer;
}