#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n)
    {
        while(n%2==0)
        {
            n/=2;
        }
        n--;
        ans++;
    }
    return ans;
}