#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CountParenthesis(string p)
{
	int cnt = 0;

	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == '(')
			cnt++;
		else
			cnt--;

		if (cnt == 0)
			return i;
	}

	return -1;
}

string dfs(string p)
{
	if (p == "")
		return p;

	string temp;
	int idx = CountParenthesis(p);
	string u = p.substr(0, idx+1);
	string v = p.substr(idx+1);

	int cnt = 0;
	bool correct = false;
	for (int j = 0; j < u.size(); j++)
	{

		if (u[j] == '(')
		{
			cnt++;
			correct = true;
		}
		else
		{
			if (cnt == 0) // 올바른거 X
			{
				for_each(u.begin() + 1, u.end() - 1, [&](char& ch)
					{
						if (ch == '(')
							ch = ')';
						else
							ch = '(';
					});
				temp = "(" + dfs(v) + ")" + u.substr(1, u.size() - 2);
				correct = false;
				break;
			}
			cnt--;
		}
	}
	if (correct)
		temp =  u + dfs(v);
	return temp;
}

string solution(string p) {
	if (p.size() == 2)
		return "()";
	string answer = dfs(p);
	return  answer;
}