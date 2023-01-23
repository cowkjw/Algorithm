#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	string findStr;
	int ans = 0;
	getline(cin, str);

	getline(cin, findStr);
	int idx = 0;

	while ((idx = str.find(findStr,idx)) != -1)
	{
		ans++;
		idx += findStr.size();
	}

	cout << ans;

	return 0;
}