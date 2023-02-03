#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second


using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v(5);
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());

	cout << sum /5<< '\n' << v[v.size() / 2];

	return 0;
}
