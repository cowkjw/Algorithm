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
	cin >> str;
	set<string> s;
	for (int i = 0; i < str.size(); i++)
	{
		string temp;
		for (int j = i; j < str.size(); j++)
		{
			temp += str[j];
			s.insert(temp);
		}
	}
	cout << s.size();
	return 0;
}
