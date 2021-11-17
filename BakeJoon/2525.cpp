#include <iostream>

using namespace std;

int main()
{
	int A, B, C;


	cin >> A >> B;

	cin >> C;

	A += C / 60;
	B += C % 60;

	if (B >= 60)
	{
		B = B % 60;
		A++;
	}
	if (A >= 24)
	{
		A %= 24;
	}
	
	cout << A << " " << B;
}

