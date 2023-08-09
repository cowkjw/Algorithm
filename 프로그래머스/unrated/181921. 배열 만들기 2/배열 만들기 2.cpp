#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;

    for(int i = l;i<=r;i++)
    {
        bool fiveZero = true;
        int temp = i;
        while(temp!=0)
        {
            if(temp%5!=0)
            {
                fiveZero = false;
                break;
            }
            temp/=10;
        }
        if(fiveZero)
        {
            answer.push_back(i);
        }
    }
    
    return answer.size()==0 ? vector<int>{-1} : answer;
}