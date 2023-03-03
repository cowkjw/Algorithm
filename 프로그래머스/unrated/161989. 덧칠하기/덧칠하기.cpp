#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int start = section.front();
    
    for(const auto& number : section)
    {
        if(start<=number)
        {
            answer++;
            start = number+m;
        }
    }
    
    
    
    return answer;
}