#include <bits/stdc++.h>
using namespace std;


int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int xN = 0;
	int bitCheck = 0;
	while (true)
	{
		xN+= N;
		int temp = xN;
		while (temp>0)
		{
			bitCheck |= 1 << (temp % 10); // 첫번째 비트를 키고 temp만큼 밀기
			temp /= 10;
		}
		if (bitCheck == (1 << 10)-1) // 9개의 비트를 키면 값이 1023
			break;
	}
	
	cout << xN;

	return 0;

}

