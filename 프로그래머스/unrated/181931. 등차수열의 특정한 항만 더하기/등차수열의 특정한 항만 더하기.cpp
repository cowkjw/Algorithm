#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    int temp = a;
    vector<int> v;
    for(int i = 1;i<=included.size();i++)
    {
        if(included[i-1])
        {
            answer+=temp;
        }
        temp+=d;
    }
    return answer;
}