#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int cnt = 0;
	cin >> N;
	int six = 665;
	string str;
	while (++six) // ��� ���Ʈ������ six�� �÷���
	{
		str = to_string(six); // ���ڿ��� ��ȯ

		if (str.find("666") != str.npos)  // ���ڿ��� 666�� �ִٸ� �� ��ȭ�� count��
			cnt++;
		if (cnt == N) // N��° ��ȭ�� count�� ���ٸ� �ش� ��ȭ���� ���
		{
			cout << six;
			break;
		}

	}


	return 0;

}

