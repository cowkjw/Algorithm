#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    
    for(int i = 1;i<=n/2;i++)
    {
        if(pow(i,2)==n)
            return 1;
    }
    
    return 2;
}