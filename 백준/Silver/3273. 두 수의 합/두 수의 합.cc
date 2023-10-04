#include <bits/stdc++.h>
using namespace std;

int arr[2000001] = {};
int N[100001] = {};

int main()
{


	int size, X, cnt = 0;

	cin >> size;




	for (int i = 0; i < size; i++)
	{
		cin >> N[i];
	}

	cin >> X;

	for (int i = 0; i < size; i++)
	{
		if (arr[X - N[i]] > 0&&X-N[i]>0)
			cnt++;

		arr[N[i]] ++;
	}

	cout << cnt;
	return 0;
}
