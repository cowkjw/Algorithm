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
	int mid = str.size()/2;
	int left = 0;
	int right = str.size()-1;

	int sum1, sum2;
	sum1 = sum2 = 0;
	while (left < mid && right >= mid)
	{
		sum1 += str[left++] - '0';
		sum2 += str[right--] - '0';
	}

	if (sum1 == sum2)
		cout << "LUCKY";
	else
		cout << "READY";

}







