#include <bits/stdc++.h>
#include <algorithm>
using namespace std;



int LCM(int A, int B)
{
	int big = B, small = A;
	int plus = B;

	if (A > B)
	{
		big = A;
		small = B;
		plus = A;
	}

	while (true)
	{
		if (big % small == 0)
			return big;
		else
		{
			big += plus;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int A, B;

		cin >> A >> B;

		int re = LCM(A, B);
		cout << re << "\n";

	}


}