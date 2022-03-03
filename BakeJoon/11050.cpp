#include <bits/stdc++.h>
using namespace std;

int Factorial(int number)
{
	if (number<= 1)
		return 1;
	else
		return Factorial(number - 1) * number;
}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;

	cin >> N >> K;

	cout << Factorial(N) / (Factorial(K) * Factorial(N - K));

	return 0;
}