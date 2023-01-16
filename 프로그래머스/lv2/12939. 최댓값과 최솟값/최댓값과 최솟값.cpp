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


string solution(string s) {
	
	vector<string> splitStr = split(s, " ");
	vector<int> v;
    
	transform(splitStr.begin(), splitStr.end(), back_inserter(v), [](string str)
		{
			return stoi(str);
		});
    
	return to_string(*min_element(v.begin(), v.end()))+ " " + to_string(*max_element(v.begin(), v.end()));;
}