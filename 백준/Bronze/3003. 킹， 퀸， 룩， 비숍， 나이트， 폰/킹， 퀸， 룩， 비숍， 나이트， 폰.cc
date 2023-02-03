#include <bits/stdc++.h>

using namespace std;

int arr[6]{ 1,1,2,2,2,8 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 6; i++)
	{
		int num;
		cin >> num;
		arr[i] -= num;
	}

	for (const auto& item : arr)
	{
		cout << item << " ";
	}
	return 0;
}
