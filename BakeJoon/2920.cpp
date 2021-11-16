#include <iostream>

using namespace std;

int main()
{
	int A[8];
	int asc = 0, des = 0;

	for (int i = 0; i < 8; i++)
	{
		cin >> A[i];
		if (A[i] == (i + 1)) asc++;
		else if (A[i] == (8 - i)) des++;
	}

	if (asc == 8) cout << "ascending";
	else if (des == 8) cout << "descending";
	else cout << "mixed";

}

