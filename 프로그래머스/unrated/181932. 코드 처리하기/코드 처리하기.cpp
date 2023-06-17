#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    bool mode = false;
    for(int i = 0;i<code.size();i++)
    {
        if(code[i]!='1')
        {
        if(!mode&&i%2==0)
        {
            answer+=code[i];
        }
        else if(mode&&i%2!=0)
        {
            answer+=code[i];
        }
        }
        else
        {
              mode=!mode;
        }
      
    }
    return answer.size()==0 ? "EMPTY": answer;
}