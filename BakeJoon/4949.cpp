#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		string str;
		stack<char> S;

		getline(cin, str);

		if (str == ".")
			break;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ')' || str[i] == ']')
			{
				if (!S.empty())
				{
					if ((S.top() == '(' && str[i] == ')') || (S.top() == '[' && str[i] == ']'))
					{
						S.pop();
					}
					else
						S.push(str[i]);
				}
				else
					S.push(str[i]);
			}
			else if (str[i] == '(' || str[i] == '[')
				S.push(str[i]);
		}
		if (S.empty())
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}



}

