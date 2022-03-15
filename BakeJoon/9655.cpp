#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int DP[1000];   // DP¸¦ È°¿ëÇÑ Ç®ÀÌ
	int N;
	cin >> N;
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		DP[i] = min(DP[i - 1] + 1, DP[i - 3] + 1);
	}

	if (DP[N] % 2 == 1)
		cout << "SK";
	else
		cout << "CY";


	//if (N % 2 != 0)  // Â¦ È¦ ÆÇ´Ü
	//	cout << "SK";
	//else
	//	cout << "CY";



}




