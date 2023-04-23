#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    for(char ch : number)
    {
        answer+=atoi(&ch);
    }
    return answer%9;
}