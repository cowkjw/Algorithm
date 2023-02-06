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

	int a, b;

	while (cin >> a >> b&& a != 0 && b != 0)
	{
		cout << ((a > b) ? "Yes" : "No")<<'\n';
	}
	return 0;
}
