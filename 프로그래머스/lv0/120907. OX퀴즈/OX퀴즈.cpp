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
        int sum = stoi(splitStr[0]);
        short oper = 0;
        for(int i = 1; i< splitStr.size();i++ )
        {
            if(splitStr[i]=="-")
            {
                oper = -1;
                continue;
            }
            else if(splitStr[i]=="+")
            {
                oper = 1;
                continue;
            }
            
            if(oper)
            {
                sum+=stoi(splitStr[i])*oper;
                oper = 0;
            }
            
            if(splitStr[i]=="=")
            {
                answer.push_back(stoi(splitStr[i+1])==sum? "O":"X");
            }
        }
    }

    
    return answer;
}