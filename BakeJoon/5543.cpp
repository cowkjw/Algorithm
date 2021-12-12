#include <iostream>

using namespace std;

int main()
{
	int a[3];
	int b[2];
	int a_Max, b_Max,i;

	
	cin >> a[0]>>a[1]>>a[2]>>b[0]>>b[1];

	a_Max = a[0], b_Max = b[0];

	for (i = 1; i < 3; i++) a_Max < a[i] ? a_Max = a_Max : a_Max = a[i];

	for (i = 1; i < 2; i++) b_Max < b[i] ? b_Max = b_Max : b_Max = b[i];

	cout << (a_Max + b_Max) - 50;
	
	
	
	return 0;

}