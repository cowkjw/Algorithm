#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    int idx = 0;
    while((idx = myString.find(pat,idx))!=-1)
    {
        idx++;
        answer++;
    }
    return answer;
}