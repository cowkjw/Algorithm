#include <iostream>

using namespace std;

int GCD(int A, int B)             // 12 4  
{
	int C = A % B;
	
	while (C != 0)
	{
		A = B; // A = 4 
		B = C;  // B = 0
		C = A % B; //C = 4
	}
	return B;
}
int LCM(int A, int B)
{
	return A * B / GCD(A, B);
}


int main()
{
	int A, B;
	cin >> A >> B;
	cout << GCD(A, B) << "\n" << LCM(A, B);

	return 0;
}


