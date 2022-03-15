#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int sum = 0;
	vector<int> v;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j < i; j++)
		{
			v.push_back(i);
		}

	}
	for (int i = N - 1; i <= M - 1; i++)
	{
		sum += v[i];
	}

	cout << sum;

}




