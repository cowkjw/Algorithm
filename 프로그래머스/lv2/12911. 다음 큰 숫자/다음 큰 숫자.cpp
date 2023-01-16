#include <string>
#include <vector>
#include<bitset>

using namespace std;

int solution(int n) {

    bitset<18> bit(n);
    
    while(n++)
    {
         bitset<18> tempBit(n);
        if(tempBit.count()==bit.count())
            return n;
    }
}