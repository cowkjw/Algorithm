#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int n, k;
vector<int> v;
int vis[200001];
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
	int s = 0, e = 0;
	int ret = -1;
	while (e < n)
	{
		if (vis[v[e]]+1>k) // 중복이면 
		{
			ret = max(ret, e - s);
			vis[v[s++]]--;
		}
		else
		{
			vis[v[e]]++;
			e++;
		}
	}
	ret = max(e - s, ret);
	cout <<ret;
	return 0;
}
