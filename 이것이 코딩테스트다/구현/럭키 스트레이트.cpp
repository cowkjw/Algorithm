#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string str = to_string(n);
	int size = str.size() / 2;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < size; i++)
	{
		sum1 += str[i] - '0';
		sum2 += str[i + size] - '0';
	}

	if (sum1 == sum2)
	{
		cout << "LUCKY";
	}
	else
	{
		cout << "READY";
	}

	return 0;
}







