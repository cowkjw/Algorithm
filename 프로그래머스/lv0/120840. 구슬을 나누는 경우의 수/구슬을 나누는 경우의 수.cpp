#include <string>
#include <vector>

using namespace std;

__int128 factorial(int n)
{
    if(n==0)
        return 1;
    
    return factorial(n-1)*n;
}


__int128 solution(int balls, int share) {
   
    return factorial(balls)/(factorial(balls-share)*factorial(share));
}