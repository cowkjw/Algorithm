#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s) return {-1};
    
    while(s!=0)
    {
        int tmp = s/n;
        if(s%n!=0)
        {
           tmp++;
        }
        answer.push_back(tmp);
        s-=tmp;
        n--;
    }
    sort(answer.begin(),answer.end());
    return answer;
}