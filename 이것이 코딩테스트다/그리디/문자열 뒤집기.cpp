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

	bool isZero = false;
	bool isOne = false;
	int zero = 0;
	int one = 0;

	for (int i = 0; i < str.size(); i++)
	{

		if (str[i] == '1')
		{
			isOne = true;
			if (isZero)
			{
				isZero = false;
				zero++;
			}
		}
		else if (str[i] == '0')
		{
			isZero = true;
			if (isOne)
			{
				isOne = false;
				one++;
			}
		}
	}

	if (str[str.size() - 1] == '1')
		one++;
	else
		zero++;

	int ans = min(one, zero);


	cout << ans;

	return 0;
}







