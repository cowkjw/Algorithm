#include <bits/stdc++.h>
using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	vector<int> V;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		V.push_back(num);
	}

	sort(V.begin(), V.end());

	cin >> M;


	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		auto lower = lower_bound(V.begin(), V.end(), num);
		auto upper = upper_bound(V.begin(), V.end(), num);

		cout << upper - lower << " ";
	}

	return 0;
}