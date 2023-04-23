#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> Split(string str ,char deli)
{
    istringstream iss(str);
    string buffer;
    vector<string> result;
    while(getline(iss,buffer,deli))
    {
        result.push_back(buffer);
    }
    return result;
}
vector<string> solution(string my_string) {
    vector<string> answer = Split(my_string,' ');
    return answer;
}