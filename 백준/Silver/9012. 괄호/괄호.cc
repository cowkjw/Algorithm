#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;

		stack<char> s;
		for (const auto& ch : str)
		{
			if (!s.empty())
			{
				if (ch == ')'&& s.top()=='(')
				{
					s.pop();
					continue;
				}
			}
			s.push(ch);
		}

		if (s.empty()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}