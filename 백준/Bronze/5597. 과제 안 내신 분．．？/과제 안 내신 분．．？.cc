#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second


using namespace std;


int arr[31];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 28; i++)
	{
		int num;
		cin >> num;
		arr[num]++;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (arr[i] == 0) cout << i << '\n';
	}
	return 0;
}
