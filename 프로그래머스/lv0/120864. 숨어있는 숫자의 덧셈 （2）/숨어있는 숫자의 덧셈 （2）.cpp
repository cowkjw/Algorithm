#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string) {
	int answer = 0;
	string temp;
	for_each(my_string.begin(), my_string.end(), [&](char& ch)
		{
			if (isdigit(ch))
			{
				temp += ch;
			}
			else
			{
				if(temp!="")
					answer += stoi(temp);
				temp = "";
			}
		});
    if(temp!="") answer+=stoi(temp);
	return answer;
}