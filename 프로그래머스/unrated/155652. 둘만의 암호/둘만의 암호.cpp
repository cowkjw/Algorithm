#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i = 0;i<s.size();i++)
    {
        char tempCh = s[i];
        int tempIdx = index;
        while(tempIdx!=0)
        {
            tempCh++;
            if(tempCh>122)
                tempCh-=26;
            if(skip.find(tempCh)==-1)
            {
                tempIdx--;
            }   
        }
        answer+=tempCh;
        
    }
    return answer;
}