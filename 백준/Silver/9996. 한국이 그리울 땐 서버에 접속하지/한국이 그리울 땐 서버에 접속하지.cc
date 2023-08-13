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

	int n;
	cin >> n;
	string pattern;
	cin >> pattern;
	string pre, suf;
	int pos = pattern.find("*");
	pre = pattern.substr(0, pos);
	suf = pattern.substr(pos+1);
	
	while (n--)
	{
		string str;
		cin >> str;
		
		if(pre.size()+ suf.size()>str.size()) cout<<"NE\n";
		else
		{

		if (pre ==str.substr(0, pre.size())&&suf==str.substr(str.size()-suf.size())) cout << "DA\n";
		else cout << "NE\n";
		}
	}

	return 0;
}
