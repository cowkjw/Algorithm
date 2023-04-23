#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    for(const auto& str : str_list)
    {
        if(str.find(ex)==-1)
        {
            answer+=str;
        }
    }
    return answer;
}