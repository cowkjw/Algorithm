#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = to_string(age);
    for (auto& c : answer)
    {
        c = c + '61';
    }
    return answer;
}