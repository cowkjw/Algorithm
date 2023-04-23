#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    for(auto& ch : myString)
    {
        if(ch=='a'||ch=='A')
        {
            ch = 'A';
        }
        else
        {
            ch = tolower(ch);
        }
    }
    return myString;
}