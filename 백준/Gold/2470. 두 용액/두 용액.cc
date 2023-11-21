#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int n;
vector<int> v;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	int ret = 2000000001;
	int ansL = l, ansR = r;
	while (l < r)
	{
		int sum = v[l] + v[r];
		if (ret > abs(sum))
		{
			ret = abs(sum);
			ansL = l;
			ansR = r;
		}
		else if (sum<0)
		{
			l++;
		}
		else r--;
	}
	cout << v[ansL] << " " << v[ansR];
	return 0;
}
