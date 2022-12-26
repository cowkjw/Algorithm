#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int size = p.size();


    for (int i = 0; i < t.size(); i++)
    {

        if (i + size <= t.size())
        {
            long long temp = stoll(t.substr(i, size));
            if (temp <= stoll(p))
                answer++;
        }

    }
    return answer;
}