#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	set<string,greater<string>>s;
	for (int i = 0; i < n; i++)
	{
		string str, str2;
		cin >> str >> str2;

		if (str2 == "leave")
		{
			if (s.count(str))
			{
				s.erase(str);
			}
		}
		else
		{
			s.insert(str);
		}
	}

	for (const auto& str : s)
	{
		cout << str << '\n';
	}
	return 0;
}