#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, k;
int che[4000001];
vector<int> prime;
void PrimeNumber()
{
	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i)
		{
			che[j] = 1;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (!che[i])
			prime.push_back(i);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	PrimeNumber();
	int l = 0;
	int r = 0;
	int ret = 0;
	int sum = 0;

	while (1)
	{
		if (sum >= n) sum -= prime[l++];
		else if (r == prime.size()) break;
		else sum += prime[r++];
		if (sum == n) ret++;
	}
	cout << ret;
	return 0;
}