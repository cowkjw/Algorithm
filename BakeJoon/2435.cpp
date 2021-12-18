#include <iostream>
using namespace std;


int main()
{

	int N, K;
	int Max = -100, temp;
	int A[100] = { 0 };
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		temp = 0;
		if (i + K > N)
		{
			break;
		}
		else
		{
			for (int j = i; j < (i + K); j++)
			{
				temp += A[j];
			}
		}
		if (temp > Max)
			Max = temp;
	}
	cout << Max;

	return 0;
}


