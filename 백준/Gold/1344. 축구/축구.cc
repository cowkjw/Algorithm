#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;

double a, b;
double dp[20][20][20];
bool isP[20];

double go(int idx, int x, int y)
{
	if (18 == idx) return isP[x] || isP[y] ? 1.0 : 0.0;
	double& ret = dp[idx][x][y];
	if (ret > -0.5) return ret;
	ret = 0.0;
	ret += go(idx + 1, x + 1, y) * a * (1 - b);
	ret += go(idx + 1, x + 1, y + 1) * a * b;
	ret += go(idx + 1, x, y) * (1 - a) * (1 - b);
	ret += go(idx + 1, x, y + 1) * (1 - a) * b;
	return ret;
}
void Era()
{
	fill(isP, isP + 20, 1);
	isP[0] = 0; isP[1] = 0;
	for (int i = 2; i <= 20; i++) 
	{
		for (int j = i + i; j <= 20; j += i)
		{
			isP[j] = 0;
		}
	}
}
int main()
{
	cin >> a;
	cin >> b;
	a /= 100, b /= 100;
	Era();
	memset(dp, -1, sizeof(dp));
	cout << fixed;
	cout.precision(6);
	cout << go(0, 0, 0);
	return 0;
}


