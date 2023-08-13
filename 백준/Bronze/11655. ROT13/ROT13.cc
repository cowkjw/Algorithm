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
	getline(cin,str);

	for (auto& ch : str)
	{
		if (ch>=65 &&ch < 97)
		{
			if (ch + 13 > 90) ch = ch + 13 - 26;
			else ch = ch + 13;
		}
		else if(ch>=97&&ch<=122)
		{
			if (ch + 13 > 122) ch = ch + 13 - 26;
			else ch = ch + 13;
		}
	} 
	cout << str;

	return 0;
}
