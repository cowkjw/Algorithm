#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
	int Numbers[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> Numbers[i];
	}
	sort(Numbers, Numbers + 3);

	cout << Numbers[1];

	return 0;
}


