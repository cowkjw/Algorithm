#include <bits/stdc++.h>
#define INF -987654321
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> v;

	while (n--)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	int answer = 0;
	for (const auto& str : v)
	{
		stack<char> s;
		for (const auto ch : str)
		{
			if (!s.empty())
			{
				if (s.top() == ch) s.pop();
				else s.push(ch);
			}
			else s.push(ch);
		}

		if (s.empty()) answer++;
	}
	cout << answer;
	return 0;
}