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


	string str;
	cin >> str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char ch;
		int start, end;
		cin >> ch >> start >> end;

		int ans = 0;
		for (int j = start; j <= end; j++)
		{
			if (ch == str[j]) ans++;
		}
		cout << ans << '\n';
	}
}