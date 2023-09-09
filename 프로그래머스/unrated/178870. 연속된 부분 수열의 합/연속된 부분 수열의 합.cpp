#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    
    int l,r;
    l = r = 0;
    int sum = sequence[0];
    int len = 2100000000;
    
    while(l<=r&&r<sequence.size())
    {
        if(sum==k)
        { 
            if(len>r-l)
            {
                answer[0] = l;
                answer[1] = r;
                len = r-l;
            }
           sum-=sequence[l++];
        }
       else if(sum<k)
        {
            sum+=sequence[++r];
        }
        else if(sum>k)
        {
            sum-=sequence[l++];
        }
  
    }
    return answer;
}