#include <iostream>
using namespace std;

int main()
{
	long long Fibo[91] = {0,1};
	int N;

	cin >> N;


	for (int i = 2; i <= N; i++)
	{

		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];

	}
	cout << Fibo[N];



	return 0;
}


