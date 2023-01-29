#include <string>
#include <vector>
#include <iostream>
using namespace std;


int GCD(int a, int b)
{
    return b ? GCD(b, a%b) : a;
}


int solution(int a, int b) {
    
    int gcd = GCD(a,b);
    int temp = b/gcd;
    
    while(temp!=1)
    {
        if(temp%2==0)
        {
            temp/=2;
        }
        else if(temp%5==0)
        {
            temp/=5;
        }
        else
        {
            return 2;
        }
    }
    
    return 1;
}