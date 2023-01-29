#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second


using namespace std;


bool Palindrome(const string& str)
{
	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	string str;
	cin >> str;
	cout<<Palindrome(str);

	return 0;
}