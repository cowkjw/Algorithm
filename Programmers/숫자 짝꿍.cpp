#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[10];
string solution(string X, string Y) {
    string answer = "";

    for (const auto& c : X)
    {
        arr[c - '0']++;
    }

    for (const auto& c : Y)
    {
        if (arr[c - '0'] != 0)
        {
            arr[c - '0']--;
            answer += c;
        }
    }

    sort(answer.rbegin(), answer.rend());

    if (answer == "")
        return "-1";
    else if (answer[0] == '0')
        return "0";

    return answer;
}