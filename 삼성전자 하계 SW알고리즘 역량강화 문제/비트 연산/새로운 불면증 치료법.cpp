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
			bitCheck |= 1 << (temp % 10); // ù��° ��Ʈ�� Ű�� temp��ŭ �б�
			temp /= 10;
		}
		if (bitCheck == (1 << 10)-1) // 9���� ��Ʈ�� Ű�� ���� 1023
			break;
	}
	
	cout << xN;

	return 0;

}

