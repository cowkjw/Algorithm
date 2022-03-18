#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    int answer = 0;
    int start = 1;
    int temp = 0;

    for (int i = start; i <= n;)
    {
        temp += i;
        i++;
        if (temp == n)
        {
            answer++;
            start++;
            i = start;
            temp = 0;
        }
        else if (temp > n)
        {
            start++;
            i = start;
            temp = 0;
        }
    }
    return answer;
}