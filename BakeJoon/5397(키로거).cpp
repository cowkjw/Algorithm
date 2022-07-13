#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int N;
	cin >> N;
	while (N--)
	{
		list<char> li = {};
		string str;
		auto cursor = li.begin();

		cin >> str;

		for (auto c : str)
		{
			if (c == '<')
			{
				if (cursor != li.begin())
					cursor--;
			}

			else if (c == '>')
			{
				if (cursor != li.end())
					cursor++;
			}

			else if (c == '-')
			{
				if (cursor != li.begin())
				{
					cursor--;
					cursor = li.erase(cursor);

				}
			}
			else
				li.insert(cursor, c);

		}
		for (auto i : li)
			cout << i;
		cout << "\n";
	}
}