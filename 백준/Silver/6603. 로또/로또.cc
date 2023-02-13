#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

vector<int> v(14);
int arr[6];
int t;
void BackTracking(int start,int cnt)
{
	if (cnt == 6)
	{
		for (const auto& i : arr)
		{
			cout << i << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <t; i++)
	{
		arr[cnt] = v[i];
		BackTracking(i + 1, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	

	while (cin >> t && t != 0)
	{

		for (int i = 0; i < t; i++)
		{
			cin >> v[i];
		}

		BackTracking(0,0);

		cout << '\n';
	}
	return 0;
}
