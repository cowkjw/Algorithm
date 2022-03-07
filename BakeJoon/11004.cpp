#include <bits/stdc++.h>
using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;

	cin >> N >> K;
	vector<int> v;

	while (N--)
	{
		int Num;
		cin >> Num;
		v.push_back(Num);
	}
	sort(v.begin(), v.end());

	cout << v[K - 1];

	return 0;
}