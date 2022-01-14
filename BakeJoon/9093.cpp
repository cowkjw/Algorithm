#include <bits/stdc++.h>
using namespace std;



int main()
{

	ios_base::sync_with_stdio(false); // 시간 줄이기
	cin.tie(NULL);
	int N;
	cin >> N;

	cin.ignore();

	while (N--)
	{

		stack<char> c;
		string s;

		getline(cin, s);
		s += ' ';
		
		for (int i = 0; i < s.size(); i++)
		{
			
			if (s[i] == ' ')
			{
				while (!c.empty())
				{
					cout << c.top();
					c.pop();
				}
				cout << " ";
			}
			else
			{
				c.push(s[i]);
			}
		}

		cout << "\n";

	}

	return 0;
}
