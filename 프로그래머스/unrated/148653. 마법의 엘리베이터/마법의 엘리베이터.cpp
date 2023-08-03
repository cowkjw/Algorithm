#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;



int solution(int storey) {
     int answer = 0;
    while(storey!=0)
    {
        int mod = storey%10; 
        storey/=10;
        
            if(mod>5 || (mod == 5 && storey%10>=5))
            {
                answer+=(10-mod);
                storey++;
            }
            else
            {
                answer+=mod;
            }
    }
    
    return answer;
}