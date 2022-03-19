#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;

    long long temp = num;
    while (temp != 1)
    {
        if (answer == 500)
        {
            return -1;
        }

        if (temp % 2 == 0)
        {
            answer++;
            temp /= 2;
        }
        else
        {
            temp = temp * 3 + 1;
            answer++;
        }
    }
    return answer;
}