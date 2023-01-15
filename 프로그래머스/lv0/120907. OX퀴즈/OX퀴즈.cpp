#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string str, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token;
	while ((pos = str.find(delimiter)) != string::npos)
	{
		token = str.substr(0, pos);
		ret.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	ret.push_back(str);
	return ret;
}


vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(const auto& str : quiz)
    {
        vector<string> splitStr = split(str," ");
        int sum = splitStr[1]=="+"? stoi(splitStr[0])+stoi(splitStr[2]):
        stoi(splitStr[0])-stoi(splitStr[2]);
        answer.push_back(stoi(splitStr[4])==sum? "O":"X");
    }

    
    return answer;
}