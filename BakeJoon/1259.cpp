#include <iostream>
#include<string>
using namespace std;


int main()
{
	string number;
	bool palind;

	while (true)
	{
		cin >> number;

		if (stoi(number) == 0)
			break;

		palind = true;
		stoi(number);

		for (int i = 0; i < number.size() / 2; i++)
		{
			if (number[i] != number[(number.size() - 1) - i])
			{
				palind = false;
				break;
			}
		}

		if (palind)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}

	return 0;
}


