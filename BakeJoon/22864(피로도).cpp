#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C, M;

	cin >> A >> B >> C >> M;

	int day = 24;
	int tired = 0;
	int work = 0;

	while (day--)
	{
		if ((tired + A) > M)
		{
			tired = max(tired - C, 0);
		}
		else
		{
			tired += A;
			work += B;
		}
	}

	cout << work;

	return 0;
}