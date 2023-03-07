#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.begin(),numbers.end());
    
    for(auto& number : answer)
    {
        number*=2;
    }
    return answer;
}