#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	string ans;
	int num = 0;

	for (const auto& c : str)
	{
		if (isdigit(c))
		{
			num += c - '0';
		}
		else
		{
			ans += c;
		}
	}

	sort(ans.begin(), ans.end());
	ans += to_string(num);

	cout << ans;

	return 0;
}







