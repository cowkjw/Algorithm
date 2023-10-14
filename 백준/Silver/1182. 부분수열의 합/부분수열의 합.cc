#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int n, s;
vector<int> v;
int ret;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i < (1 << n); i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				sum += v[j];
			}
		}

		if (sum == s) ret++;
	}
	cout << ret;
	return 0;
}
