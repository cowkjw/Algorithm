#include <iostream>

using namespace std;

int main()
{

	int x[3], y[3];
	int check_x, check_y, count = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}
	check_x = x[0];
	check_y = y[0];

	if (check_x == x[1])
	{
		cout << x[2] << " ";
	}
	else if (check_x == x[2])
	{
		cout << x[1] << " ";
	}
	else cout << check_x << " ";

	if (check_y == y[1])
	{
		cout << y[2] << " ";
	}
	else if (check_y == y[2])
	{
		cout << y[1] << " ";
	}
	else cout << check_y<< " ";
}