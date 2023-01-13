#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int idx = 0;
    while(--k)
    {
        idx=(idx+2)%numbers.size();
    }
    return numbers[idx];
}