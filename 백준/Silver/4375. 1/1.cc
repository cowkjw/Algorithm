#include <bits/stdc++.h>
#define INF -987654321
typedef long long ll;
using namespace std;

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int cnt = 1, ret = 1;
		while (true)
		{
			if (cnt % n == 0)
			{
				cout << ret <<'\n';
				break;
			}
			else
			{
				cnt = (cnt * 10) + 1;
				cnt %= n;
				ret++;
			}
		}
	}
	return 0;
}