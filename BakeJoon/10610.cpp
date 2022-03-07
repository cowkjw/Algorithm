#include <bits/stdc++.h>
using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	sort(s.rbegin(), s.rend());

	long long a = 0;

	for (auto i : s)
		a += atoi(&i);

	if (a % 3 == 0&&s[s.size()-1]=='0')
		cout << s;
	else
		cout << -1;


	return 0;
}