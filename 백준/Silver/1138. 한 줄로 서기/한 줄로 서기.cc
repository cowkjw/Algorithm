#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int n;
int arr[11];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];
	vector<int> v;
	for (int i = 1; i <= n; i++) v.push_back(i);

	for(int i = 1;i<=n;i++)
	{
		int cnt = 0;
		int idx = find(v.begin(), v.end(), i)- v.begin();
		int temp = 1;
		while (idx+temp < n)
		{
			if (cnt == arr[i])
			{
				break;
			}
			if (v[idx + temp] > i)
			{
				swap(v[idx], v[idx + temp]);
				idx = idx + temp;
				temp = 1;
				cnt++;
				continue;
			}
			temp++;
		}
	}

	for (auto i : v) cout << i << " ";
	return 0;
}
