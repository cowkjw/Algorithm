#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int i= 0,j = 0;
    for(int n = 0;n<str1.size()+str2.size();n++)
    {
        if(n%2==0)
        {
            answer+=str1[i++];
        }
        else
        {
            answer+=str2[j++];
        }
    }
    return answer;
}