#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n; // 5
	vector<int> fear(n); // 2 3 1 2 2
	for (int i = 0; i < n; i++)
		cin >> fear[i];

	sort(fear.begin(), fear.end());

	int ans = 0;
	int cnt = 0;

	for (const auto& item : fear)
	{
		cnt++;
		if (cnt >= item)
		{
			ans++;
			cnt = 0;
		}

	}

	cout << ans;

	return 0;
}







