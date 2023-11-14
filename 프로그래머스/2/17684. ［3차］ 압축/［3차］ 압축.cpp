#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> m;
	for (int i = 0; i < 26; i++)
	{
		string a;
		a += (char)('A' + i);
		m[a] = i + 1;
	}

	for (int i = 0; i < msg.size();)
	{
		int len = 1;
		string c;
		if (i + 1 == msg.size())
		{
			answer.push_back(m[msg.substr(i)]);
			break;
		}

		while (m.find(msg.substr(i, len)) != m.end()&&i+len<=msg.size())
		{
			len++;
		}

		c = msg.substr(i, len);
		answer.push_back(m[msg.substr(i, len - 1)]);

		if (i + (len - 1) <= msg.size())
		{
			m[c] = m.size() + 1;
			i += len - 1;
		}
		else i++;
	}
	return answer;
}