#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	list<int> li;

	int N;
	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int num;
			cin >> num;
			li.push_back(num);
		}
		else if (s == "pop")
		{
			if (li.empty())
				cout << -1 << "\n";
			else
			{
				cout << li.front() << "\n";
				li.pop_front();
			}
		}
		else if (s == "front")
		{
			if (li.empty())
				cout << -1 << "\n";
			else
				cout << li.front() << "\n";

		}
		else if (s == "back")
		{
			if (li.empty())
				cout << -1 << "\n";
			else
				cout << li.back() << "\n";
		}
		else if (s == "size")
			cout << li.size() << "\n";
		else if (s == "empty")
			cout << li.empty() << "\n";
	}

	return 0;
}




