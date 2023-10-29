#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s) return {-1};
    
    while(s!=0)
    {
        int tmp = s%n == 0 ? s/n : s/n+1;
        answer.push_back(tmp);
        s-=tmp;
        n--;
    }
    sort(answer.begin(),answer.end());
    return answer;
}