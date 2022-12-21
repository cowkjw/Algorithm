#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) { // a는 마트에 줘야하는 병수 b는 갖다주면 받는 병 수
    // 가지고 있는 빈병
    int answer = 0;

    while (n >= a)
    {
        answer += (n / a) * b;
        n = (n / a) * b + n % a;
    }



    return answer;
}