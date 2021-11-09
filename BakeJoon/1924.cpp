#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;

int main() {

	int x, y, sum = 0; // 2007 1 1 >> MON 1 8 15 22 29// 5 12 19 26// 5 12 19 26// 2 9 16 23 30// 7 
	int* Month = new int[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };//  TUE 2 9 16 23 30 // 6 13 20 27 // 6 13 20 27 // 3 10 17 24 1

	cin >> x >> y;
	sum += y;
	for (int i = 0; i < x - 1; i++)
	{
		sum += Month[i];
	}
	switch (sum % 7)
	{

	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 0:
		cout << "SUN";
		break;
	}

}