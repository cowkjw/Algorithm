#include <bits/stdc++.h>
using namespace std;


int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		int N, M;
		cin >> N >> M;
		int bitCheck = (1 << N) - 1;  // 1111���� 1�� ���� 111�� ��
		if ((M&bitCheck)==bitCheck) // and�����ڷ� ���� ������ 1�� ��ȯ
			cout << "ON" << '\n';
		else
			cout << "OFF"<<'\n';
	}



	return 0;

}

