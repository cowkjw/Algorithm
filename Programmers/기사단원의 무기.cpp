#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;

    int temp;
    for (int i = 2; i <= number; i++) // 1�� ������ 1��
    {
        temp = 1; // ��� ���� �ڱ� �ڽ� ������ ���� 1�� �ʱ�ȭ
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