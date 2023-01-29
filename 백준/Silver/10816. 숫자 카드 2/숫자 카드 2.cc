#include <bits/stdc++.h>
using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	vector<int> V;
	cin >> N;

	V.resize(20000001, 0);


	int limit = 20000001;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		V[num + 10000000]++;

	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		cout << V[num + 10000000] << " ";
	}

	return 0;
}