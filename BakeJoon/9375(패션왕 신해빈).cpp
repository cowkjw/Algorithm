#include <bits/stdc++.h>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, int> m;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int ans = 1;
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++)
		{

			string key, val;
			cin >> key >> val;

			m[val]++; // 있다면 개수 ++
		}

		for (auto i : m)
			ans *= i.second+1;
		cout << ans - 1<<"\n"; // 알몸인 경우 -1
		m.clear();
	}
	return 0;

}

