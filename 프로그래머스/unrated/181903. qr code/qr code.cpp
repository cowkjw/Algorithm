#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
    string answer = "";
    vector<pair<char,int>> v;
    
    for(int i = 0;i<code.size();i++)
    {
        v.push_back({code[i],i%q});
    }
    for(const auto& it : v)
    {
        if(it.second == r)
        answer.push_back(it.first);
    }
    return answer;
}