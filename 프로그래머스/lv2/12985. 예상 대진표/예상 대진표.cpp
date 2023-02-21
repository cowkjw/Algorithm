#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(abs(a-b)!=0)
    {
       
        answer++;
        a=ceil(float(a)/2);
        b=ceil(float(b)/2);
    }


    return answer;
}