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

	int x;
	cin >> x;
	int sum = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}

	sum == x ? cout << "Yes" : cout << "No";
	return 0;
}
