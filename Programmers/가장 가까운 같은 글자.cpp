#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.size(), -1);

    for (int i = 1; i < s.size(); i++)
    {
        int cnt = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (s[i] == s[j])
            {
                cnt = i - j;
                break;
            }
        }
        if (cnt != 0)
            answer[i] = cnt;
    }

    return answer;
}