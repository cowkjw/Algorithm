#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size();
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            index = 0;
            continue;
        }
        if (index % 2 == 0)
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);

        index++;
    }
    answer = s;
    return answer;
}