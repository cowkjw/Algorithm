#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    for(int n = 0;n<str1.size();n++)
    {
      answer.push_back(str1[n]);
        answer.push_back(str2[n]);
    }
    return answer;
}