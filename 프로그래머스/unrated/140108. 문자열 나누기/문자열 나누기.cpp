#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp;
    temp+=s[0];
    int same = 1;
    int diff = 0;
    for(int i = 1;i<s.size();i++)
    {
        if(temp=="")
        {
            temp+=s[i];
            continue;
        }
        if(temp.back()==s[i])
        {
            same++;
        }
        else
        {
            diff++;
        }
        
        if(same==diff)
        {
            same = 1;
            diff = 0;
            answer++;
            temp ="";
        }
    }
    if(temp!="")
        answer++;
    return answer;
}