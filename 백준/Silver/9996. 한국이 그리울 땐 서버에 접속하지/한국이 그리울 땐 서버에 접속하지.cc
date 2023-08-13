#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

vector<string> split(string input, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string pattern;
	cin >> pattern;
	vector<string> v = split(pattern, "*");
	
	while (n--)
	{
		string str;
		cin >> str;
		
		if(v[0].size()+v[1].size()>str.size()) cout<<"NE\n";
		else
		{

		if (v[0]==str.substr(0,v[0].size())&&v[1]==str.substr(str.size()-v[1].size())) cout << "DA\n";
		else cout << "NE\n";
		}
	}

	return 0;
}
