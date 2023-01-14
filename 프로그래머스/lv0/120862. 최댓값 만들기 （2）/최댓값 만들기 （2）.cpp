#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {

    int answer = -100000001;
    for(int i = 0;i<numbers.size()-1;i++)
    {
        for(int j = i+1;j<numbers.size();j++)
        {
            answer = max(answer,numbers[i]*numbers[j]);
        }
    }
    
    return answer;
}