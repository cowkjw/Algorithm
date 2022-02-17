#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int isP = 0, isY = 0;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == 'p' || s[i] == 'P')
            isP++;
        else if (s[i] == 'y' || s[i] == 'Y')
            isY++;
    }

    if (isP == isY)
        return answer;
    else
        return !answer;

}