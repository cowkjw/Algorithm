#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int N;
	int* Numbers;

	cin >> N;

	Numbers = new int[N];


	for (int i = 0; i < N; i++)
	{
		cin >> Numbers[i];
	}

	sort(Numbers, Numbers + N);

	for (int i = 0; i < N; i++)
	{
		cout << Numbers[i] << "\n";
	}

	delete[] Numbers;
	
}