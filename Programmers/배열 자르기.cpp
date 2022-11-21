#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer;

    while (num1 <= num2)
    {
        answer.push_back(numbers[num1++]);
    }
    return answer;
}