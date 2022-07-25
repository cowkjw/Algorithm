#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arrX[10];
int arrY[10];

string solution(string X, string Y) {
    string answer = "";

    for (auto i : X)
    {
        arrX[i - '0']++;
    }
    for (auto i : Y)
    {
        arrY[i - '0']++;
    }

    for (int i = 9; i >= 0; i--)
    {
        if (arrX[i] > 0 && arrY[i] > 0)
        {
            int mn = min(arrX[i], arrY[i]);
            for (int j = 0; j < mn; j++)
            {
                answer += (i + '0');
                arrX[i]--;
                arrY[i]--;
            }
        }
    }

    if (answer.front() == '0')
    {
        answer = '0';
    }
    if (answer == "")
    {
        answer = "-1";
    }

    return answer;
}