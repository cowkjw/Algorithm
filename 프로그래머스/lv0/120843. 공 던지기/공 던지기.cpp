#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    
    int idx = -2;
    while(k--)
    {
        idx=(idx+2)%numbers.size();
    }
    return numbers[idx];
}