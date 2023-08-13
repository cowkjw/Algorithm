#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int a, b, c;
int arr[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		int s, e;
		cin >> s >> e;
		for (; s < e; s++)
		{
			arr[s]++;
		}
	}
	int sum = 0;
	for (auto i : arr)
	{
		if (i == 1)
		{
			sum += a;
		}
		else if (i == 2)
		{

			sum += b*2;
		}
		else if (i == 3)
		{
			sum += c*3;

		}
	}

	cout << sum;

	return 0;
}
