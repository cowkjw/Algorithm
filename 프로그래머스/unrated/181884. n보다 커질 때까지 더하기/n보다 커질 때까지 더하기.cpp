#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    auto it = numbers.begin();
    while(answer<=n)
    {
        answer+=*it++;
    }
    return answer;
}