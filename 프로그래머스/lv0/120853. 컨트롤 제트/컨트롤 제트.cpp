#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token;
	while((pos = str.find(delimiter)) != string::npos)
    {
		token = str.substr(0, pos);
		ret.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	ret.push_back(str);
	return ret;
}


int solution(string s) {
    int answer = 0;
    vector<string> splitStr = split(s," ");
    int prevNum;
    for(const auto& str : splitStr)
    {
        if(str=="Z")
        {
            answer-=prevNum;
        }
        else
        {
            int num = stoi(str);
            answer += num;
            prevNum = num;
        }
      
    }
   
    return answer;
}