#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int size = numbers.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size - 1; j++)
            answer.push_back(numbers[i] + numbers[j + 1]);
    }
    sort(answer.begin(), answer.end());

    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}