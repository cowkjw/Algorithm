#include <iostream>
using namespace std;

int main()
{

	int num;
	int Max = 0;
	int index;

	for (int i = 0; i < 9; i++)
	{
		cin >> num;
		if (Max < num)
		{
			Max = num;
			index = i;
		}
	}

	cout << Max << "\n" << index + 1;


	return 0;
}


