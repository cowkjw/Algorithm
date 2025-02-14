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
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	map<char, int > m;
	for (int i = 0; i < 6; i++)
	{
		m[('A' + i)] = 10 + i;
	}
	string str;
	cin >> str;
	int ans = 0;
	for (const char ch : str)
	{
		if (ch >= '0' && ch <= '9')
		{
			ans = ans * 16 + (ch - '0'); // 숫자 처리
		}
		else if (m.find(ch) != m.end()) // 'A'-'F' 처리
		{
			ans = ans * 16 + m[ch];
		}
	}
	cout << ans;
	return 0;
}