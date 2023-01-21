#include <string>
#include <vector>

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

string solution(string polynomial) {
    string answer = "0";
    vector<string> splitStr = split(polynomial," ");
    int cnt = 0;
    int temp= 0;
    for(const auto& str : splitStr)
    {
       if (str.find("x") != -1)
		{
			if (str.size() != 1)
			{
				cnt += stoi(str.substr(0, str.size() - 1));
			}
			else
			{
				cnt++;
			}
		}
		else if (str != "+")
		{
			temp += stoi(str);
		}
    }
    
    if(temp!=0&&cnt!=0)
    {
        if(cnt==1)
        {
           answer= "x + "+to_string(temp);
        }
        else
        {
            answer=to_string(cnt)+"x"+" + "+to_string(temp);
        }
    }
   
    else if(temp == 0&&cnt!=0)
	{
		if (cnt == 1)
		{
			answer = "x";
		}
		else
		{
			answer = to_string(cnt) + "x";

		}
	}
    else if(temp!=0&&cnt==0)
    {
        answer=to_string(temp);
    }

    
    return answer;
}