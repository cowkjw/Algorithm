#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int year(int E, int S, int M)
{
	int year = 1;
	int e = 1, s = 1, m = 1;

	while (true)
	{

		if (e == E && s == S && m == M)
		{
			return year;
		}

		e++;
		s++;
		m++;
		year++;

		if (e > 15)
			e = 1;
		if (s > 28)
			s = 1;
		if (m > 19)
			m = 1;
	}

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int E, S, M;

	cin >> E >> S >> M;

	int ans = year(E, S, M);
	cout << ans;


}
