#include <iostream>
#include <string>

using namespace std;



int main()
{

	int arr[10] = { 0 };
	string num;
	int count = 0;
	cin >> num;

	for (int i = 0; i < num.size(); i++)
	{
		arr[num[i] - 48]++;
	}

	int sn = (arr[6] + arr[9] + 1) / 2;

	arr[6] = arr[9] = sn;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > count)
			count = arr[i];
	}

	cout << count;


	return 0;
}