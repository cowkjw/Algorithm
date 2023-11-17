#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321


void PrintScore(int c ,int Min,int Max,int gap)
{
	cout << "Class " << c << "\n";
	cout << "Max "<< Max<<", Min "<<Min<<", Largest gap " << gap << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i =0; i < t; i++)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.rbegin(), v.rend());

		PrintScore(i+1, v.back(), v.front(), [&]() {
			int gap = 0;
			for (int j = 0; j < v.size()-1; j++)
			{
				gap = max(gap, abs(v[j] - v[j + 1]));
			}
			return gap;
			; }());
	}
	return 0;
}
