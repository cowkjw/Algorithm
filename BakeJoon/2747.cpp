#include <iostream>

using namespace std;

int main()
{

	int N, a=0, b=1;
	int temp;
	cin >>N;


	for (int i = 0; i < N-1; i++)
	{
		temp = a + b; //1 2 3
		a = b;// a ==1 a== 1 a==2
		b = temp; //b==1; b==2 b== 3

	}
	cout << b;

}