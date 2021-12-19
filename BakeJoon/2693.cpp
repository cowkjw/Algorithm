#include <iostream>

using namespace std;


int main()
{

	
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int A[10];

		for (int i = 0; i < 10; i++)
		{

			cin >> A[i];
		}

		for (int i = 0; i < 10; i++)
		{
			int temp = 0;
			for (int j = i; j < 10; j++)
			{
				if (A[i] > A[j])
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
		}

	cout << A[7]<<"\n";

	}





	return 0;
}


