#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, ret;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < 32; i++)
	{
		if (n & (1 << i))
		{
			ret++;
		}
	}
	cout << ret;
	return 0;
}