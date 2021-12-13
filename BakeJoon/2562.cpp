#include <iostream>
using namespace std;

int main()
{

	int numbers[10] = {};
	int Max = numbers[0];
	int index;

	for (int i = 0; i < 9; i++)
	{
		cin >> numbers[i];
		if (Max < numbers[i])
		{
			Max = numbers[i];
			index = i;
		}
	}

	cout << Max << "\n" << index+1;


	return 0;
}


