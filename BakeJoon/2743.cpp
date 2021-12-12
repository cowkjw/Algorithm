#include <iostream>

using namespace std;

int main()
{

	char* str = new char[101];

	int count = 0;
	cin >>str;

	while (*str)
	{
		str++;
		count++;

	}

	cout << count;

	
}