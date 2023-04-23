#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    for(const auto index : indices)
    {
        my_string.replace(index,1," ");
    }
    for(const auto ch : my_string)
    {
        if(ch!=' ')
        {
            answer+=ch;
        }
    }
    return answer;
}