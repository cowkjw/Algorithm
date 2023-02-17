#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string N;
	list<char> L;
	int M;

	cin >> N;

	for (auto i : N)
		L.push_back(i);

	auto cursorPos = L.end();

	cin >> M;

	while (M--)
	{
		char com;
		cin >> com;

		if (com == 'P')
		{
			char add;
			cin >> add;
			L.insert(cursorPos, add);
		}
		else if (com == 'L')
		{
			if (cursorPos != L.begin())
				cursorPos--;
		}
		else if (com == 'D')
		{
			if (cursorPos != L.end())
				cursorPos++;
		}
		else if (com == 'B')
		{
			if (cursorPos != L.begin())
			{
				cursorPos--;
				cursorPos = L.erase(cursorPos);
			}
		}

	}
	for (auto i : L)
		cout << i;
}
