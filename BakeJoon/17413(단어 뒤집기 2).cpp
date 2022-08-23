#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> v;
	string str;
	stack<char> s;
	getline(cin, str);
	bool flag = false;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '<')
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			flag = true;
			cout << str[i];
			continue;
		}
		else if (str[i] == ' '&&!flag)
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << ' ';
		}

		if (flag)
		{
			cout << str[i];
			if (str[i] == '>')
				flag = false;
		}
		else
		{
			if (str[i] != ' ')
				s.push(str[i]);
		}
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}



}







