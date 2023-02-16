#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
	unordered_map<int, int> m;
		int n1, n2;
		cin >> n1;
		for (int i = 0; i < n1; i++)
		{
			int num;
			cin >> num;
			m[num]=1;
		}
		cin >> n2;
		for (int i = 0; i < n2; i++)
		{
			int num;
			cin >> num;
			cout << m[num] << '\n';
		}
	}

	return 0;
}
