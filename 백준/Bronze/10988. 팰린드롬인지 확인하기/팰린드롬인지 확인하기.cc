#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	string temp = str;

	reverse(temp.begin(), temp.end());
	if (temp == str) cout << 1;
	else cout << 0;

	return 0;
}
