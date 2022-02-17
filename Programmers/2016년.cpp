#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    vector<string> days = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
    vector<int> month = { 31,29,31,30,31,30,31,31,30,31,30,31 };

    int total = b;

    for (int i = 0; i < a - 1; i++)
        total += month[i];

    answer = days[total % 7];


    return answer;
}