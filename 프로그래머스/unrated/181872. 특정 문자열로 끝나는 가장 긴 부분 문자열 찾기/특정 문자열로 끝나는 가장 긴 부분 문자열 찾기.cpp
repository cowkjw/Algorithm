#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    int idx = 0 ;
    while(myString.find(pat,idx)!=-1)
    {
        idx++;
    }
    answer = myString.substr(0,idx+pat.size()-1);
    return answer;
}