#include <iostream>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> vecEmptyLen;
    
    int startEmpty = 1;
    
    for(const int station : stations)
    {
        int left = max(station-w,1);
        int right = min(n,station+w);
        if(startEmpty<left)
        {
            vecEmptyLen.push_back(station-w-startEmpty);
        }
       
        startEmpty = right+1;
    }
    if(startEmpty<=n)
    {
         vecEmptyLen.push_back(n-startEmpty+1);
    }
   
    for(const int emtLen : vecEmptyLen)
    {
        int range = 2 * w + 1; 
        answer += (emtLen + range - 1) / range; 
    }
    
    return answer;
}