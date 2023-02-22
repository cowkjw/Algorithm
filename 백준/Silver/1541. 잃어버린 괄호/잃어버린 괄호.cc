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
	bool isMinus = false;
	int ans = 0;
	string temp;
	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == '-' || str[i] == '+' || i == str.length())
		{
			if (isMinus)
			{
				ans -= stoi(temp);
				temp = "";
			}
			else
			{
				ans += stoi(temp);
				temp = "";
			}
		}
		else
		{
			temp += str[i];
		}
		if (str[i] == '-')
			isMinus = true;
	}


	cout << ans;
}