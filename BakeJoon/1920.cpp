#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	vector<int> V;

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		int Num;
		cin >> Num;
		V.push_back(Num);

	}

	sort(V.begin(), V.end());
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int _Num;
		cin >> _Num;
		if (binary_search(V.begin(), V.end(), _Num))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

}

