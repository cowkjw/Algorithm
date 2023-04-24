#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    for(const auto& str : order)
    {
        if(str.find("latte")!=-1)
        {
            answer+=5000;
        }
        else
        {
            answer+=4500;
        }
    }
    return answer;
}