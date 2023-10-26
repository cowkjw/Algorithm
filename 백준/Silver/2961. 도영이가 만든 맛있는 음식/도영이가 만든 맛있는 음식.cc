#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
int n;
int vis[11];
struct Food
{
	int s, b;
};
vector<Food> v;
int ret = INF;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int s, b;
		cin >> s >> b;
		v.push_back({ s,b });
	}

	for (int i = 1; i < (1 << n); i++)
	{
		int a = 1;
		int b = 0;
		for (int j = 0; j < n; j++)
		{
			if (i &(1<<j))
			{
				a *= v[j].s;
				b += v[j].b;
			}
		}
		ret = min(abs(a - b), ret);
	}
	cout << ret;
	return 0;
}


