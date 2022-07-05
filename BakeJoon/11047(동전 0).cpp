#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,K;
	cin >> N>>K;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (K >= temp)
			v.push_back(temp);
		
	}

	sort(v.rbegin(), v.rend());
	int cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		while (K - v[i] >= 0)
		{
			cnt++;
			K -= v[i];
		}
	}

	cout << cnt;



	return 0;

}

