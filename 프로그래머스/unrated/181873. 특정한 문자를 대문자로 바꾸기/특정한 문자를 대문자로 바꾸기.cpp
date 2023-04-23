#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string my_string, string alp) {
    int idx = 0;
    
    while((idx=my_string.find(alp))!=-1)
    {   
        my_string.replace(idx,1,1,toupper(alp[0]));
    }
    return my_string;
}