#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start, int end) {
    vector<int> answer;
    for(;start<=end;start++)
    {
        answer.push_back(start);
    }
    return answer;
}