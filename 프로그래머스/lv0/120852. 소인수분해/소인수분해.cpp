#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool arr[10001];
vector<int> solution(int n) {
    vector<int> answer;
    
    
    while(n>1)
    {
        int cnt = 0;
        for(int i = 2;i<=n;i++)
        {
            if(n%i==0)
            {
                arr[i] = true;
                n/=i;
                break;
            }
        }
    }
    
    for(int i = 2;i<=10001;i++)
    {
        if(arr[i]==true)
        {
            answer.push_back(i);
        }
    }
      return answer;
}