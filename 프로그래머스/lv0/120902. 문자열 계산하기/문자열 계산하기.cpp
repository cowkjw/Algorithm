#include <string>
#include <vector>

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

int solution(string my_string) {
	vector<string> splitStr = split(my_string, " ");
	short oper = 0; //-1 minus 1 plus
	int answer = stoi(splitStr[0]);
	for (int i = 1;i<splitStr.size();i++)
	{
		if (splitStr[i] == "-" || splitStr[i] == "+")
		{
			if (splitStr[i] == "-")
			{
				oper = -1;
			}
			else
			{
				oper = 1;
			}
			continue;
		}

		if (oper)
		{
			answer += (stoi(splitStr[i]) * oper);
			oper = 0;
		}
	}
	return answer;
}