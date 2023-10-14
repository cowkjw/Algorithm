#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int n, k;
vector<int> v;
int vis[9];
int ret;
void go(int weight,int cnt)
{
	if (weight < 500)
		return;
	if (cnt == n)
	{
		ret++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		go(weight + v[i] - k,cnt+1);
		vis[i] = 0;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	go(500,0);
	cout << ret;
	return 0;
}
