#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int rope;
		cin >> rope;
		v.push_back(rope);
	}

	sort(v.rbegin(), v.rend());

	int max = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int remind = v[i] * (i + 1);
		
		if (remind > max)
		{
			max = remind;
		}

	}

	cout << max;
	return 0;
}




