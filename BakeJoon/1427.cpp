#include <iostream>
using namespace std;



int main()
{
	int arr[10]{ 0 };
	int N;
	
	cin >> N;

	while (N != 0)
	{
		arr[N % 10]++;
		N=N / 10;
	}

	for (int i = 9; i >=0; i--)
	{
		
		while (arr[i] != 0)
		{
			cout << i;
			arr[i]--;
		}
	}


	

	return 0;
}


