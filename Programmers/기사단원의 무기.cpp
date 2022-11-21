#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;

    int temp;
    for (int i = 2; i <= number; i++) // 1은 어차피 1개
    {
        temp = 1; // 약수 개수 자기 자신 포함을 위해 1로 초기화
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                temp++;
            }
        }
        if (temp <= limit)
        {
            answer += temp;
        }
        else
        {
            answer += power;
        }
    }
    return answer;
}