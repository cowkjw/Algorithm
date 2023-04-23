#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    for(const auto& num : num_str)
    {
        answer+=(num-'0');
    }
    return answer;
}