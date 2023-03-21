
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer(numbers.size(), -1);
    stack<int> s;

    for (int i = 0; i < numbers.size(); i++)
    {
        int number = numbers[i];

        while (!s.empty() && number > numbers[s.top()]) 
        {
            answer[s.top()] = number; // 이전 값의 정답을 현재 숫자로
            s.pop();
        }
        s.push(i);
    }

    return answer;
}