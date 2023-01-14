#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> V;
	int N;

	cin >> N;

	while (N != 1)
	{
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0)
			{
				N /= i;
				V.push_back(i);
				break;
			}
		}
	}
	

	sort(V.begin(), V.end());

	for (auto i = 0; i < V.size(); i++)
	{
		cout << V[i] << "\n";
	}

}

