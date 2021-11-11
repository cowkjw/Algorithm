#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[3],i;
	int a_max, a_min, a_mid;



	cin >> a[0] >> a[1] >> a[2];


	a_max = a[0];
	a_min = a[0];
	a_mid = 0;

	for (i = 1; i < 3; i++)
	{
		a[i] > a_max ? a_max = a[i] : a_max = a_max;
		a[i] < a_min ? a_min = a[i] : a_min = a_min;

	}
	for (i = 0; i < 3; i++)
	{
		if (a_max!=a[i]&&a_min!=a[i])
		{
			a_mid = a[i];
			break;
		}
	}

	cout << a_min<<" "<< a_mid <<" "<< a_max;


	//sort(a, a + 3);    sort함수 사용

	//for (i = 0; i < 3; i++)
	//{
	//	cout << a[i] << " ";
	//}



	
	return 0;

}