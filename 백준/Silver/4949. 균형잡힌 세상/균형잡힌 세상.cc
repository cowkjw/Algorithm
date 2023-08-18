#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true)
	{
		string str;
		getline(cin, str);
		if (str[0] == '.') break;
		stack<char> s;
		for (const auto& ch : str)
		{
			if (ch == '(' || ch == ')' || ch == '[' || ch == ']')
			{
				if (!s.empty())
				{
					if ((ch == ')' && s.top() == '(') ||( ch == ']' && s.top() == '['))
					{
						s.pop();
						continue;
					}
				}
				s.push(ch);
			}
		}
		if (s.empty()) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}