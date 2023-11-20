#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;

int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int w = 0;
	int ret = n == 0? 0: 1;
	for (int i = 0; i < n; i++)
	{
		if (w + v[i] > m)
		{
			ret++;
			w = v[i];
		}
		else w += v[i];
	}
	cout << ret;
	return 0;
}

