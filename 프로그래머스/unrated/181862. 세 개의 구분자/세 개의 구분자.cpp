#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    string tempStr = "";
    for(const auto& ch : myStr)
    {
        if(ch!='a'&&ch!='b'&&ch!='c')
        {
            tempStr+=ch;
        }
        else
        {
            if(tempStr.size()!=0)
            {
                answer.push_back(tempStr);
            }
            
            tempStr = "";
        }
    }
    if(tempStr.size()!=0)
    {
        answer.push_back(tempStr);
    }
    if(answer.size()==0)
    {
        answer.push_back("EMPTY");
    }
    return answer;
}