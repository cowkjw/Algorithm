#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
typedef long long ll;


int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int ret = 0;


	while (n > 0)
	{
		if (n % 5 == 0)
		{
			cout << ret + n / 5;
			return 0;
		}
		n -= 2;
		ret++;
	}
	if (n < 0)
	{
		cout << -1;
	}
	else 
	{
		cout << ret;
	}
	return 0;
}

