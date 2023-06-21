#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string temp;
    for(const auto& ch : myString)
    {
        if(ch=='x')
        {
            if(temp!="")
            answer.push_back(temp);
            temp = "";
        }
        else
        {
            temp+=ch;
        }
    }
    if(temp!="")
        answer.push_back(temp);
    sort(answer.begin(),answer.end());
    return answer;
}