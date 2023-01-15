#include <string>
#include <vector>

using namespace std;

int solution(int n) {
   int i = 1;
    while(i)
    {
        if((6*i)%n==0)
        {
            return i;
        }
        i++;
    }

}