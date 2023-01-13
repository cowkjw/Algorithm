#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

string solution(string my_string) {
    
    string answer ="";
    
    for(const auto& c : my_string)
    {
        if(answer.find(c)==-1)
            answer+=c;
    }
    
    return answer;
}