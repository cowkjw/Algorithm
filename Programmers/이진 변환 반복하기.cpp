#include <string>
#include <vector>

using namespace std;

int countZero;
int countBinary;

string eraseZero(string s)
{
	string temp;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '0')
		{
			temp += s[i];
		}
		else
		{
			countZero++;
		}
	}
	return temp;
}

string toBinary(string s)
{
	int size = s.size();
	string temp;
	vector<char> v;
	while (size != 0)
	{
		if (size % 2 == 0)
		{
			v.push_back('0');
		}
		else
		{
			v.push_back('1');
		}
		size /= 2;

	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		temp += v[i];
	}

	return temp;
}


vector<int> solution(string s) {
	vector<int> answer;

	string temp = s;
	while (temp != "1")
	{
		if (temp.find("0") != temp.npos)
		{
			temp = eraseZero(temp);
		}

		temp = toBinary(temp);
		countBinary++;
	}

	answer.push_back(countBinary);
	answer.push_back(countZero);


	return answer;
}