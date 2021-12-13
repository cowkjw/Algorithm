#include <iostream>
using namespace std;

int main()
{

	int N, A;
	int Min = 1000000, Max = 2;

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> A;

		Min > A ? Min = A : Min = Min;
		A > Max ? Max = A : Max = Max;
	}

	if (N == 1 && A == 2)
	{
		cout << A * 2;
	}
	else
		cout << Min * Max;

	return 0;
}


