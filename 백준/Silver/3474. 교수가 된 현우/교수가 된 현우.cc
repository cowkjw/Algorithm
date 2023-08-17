#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--)
	{
		int num;
		cin >> num;

		int  ret5 = 0;

		for (int i = 5; i <= num; i *= 5)
		{
			ret5 += num / i;
		}
		cout << ret5 << '\n';
	}

	return 0;
}