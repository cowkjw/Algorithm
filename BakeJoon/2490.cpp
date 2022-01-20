#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C, D;

	for (int i = 0; i < 3; i++)
	{
		cin >> A >> B >> C >> D;

		int sum = A + B + C + D;

		if (sum == 4)
			cout << "E" << "\n";
		else if (sum == 3)
			cout << "A" << "\n";
		else if (sum == 2)
			cout << "B" << "\n";
		else if (sum == 1)
			cout << "C" << "\n";
		else
			cout << "D" << "\n";
	}

}

