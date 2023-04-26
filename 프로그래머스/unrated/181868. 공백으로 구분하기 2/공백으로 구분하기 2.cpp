#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string temp;
    for(const auto& ch : my_string)
    {
        if(ch==' ')
        {
            if(temp.size()!=0)
            {
                answer.push_back(temp);
                
                temp.clear();
                continue;
            }
        }
        else
        {
            temp+=ch;
        }
        
    }
    if(temp.size()!=0)
    answer.push_back(temp);
    return answer;
}