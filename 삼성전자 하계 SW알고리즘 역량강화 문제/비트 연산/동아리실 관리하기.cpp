#include <bits/stdc++.h>
using namespace std;

int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int T;
	cin >> T;

	while (T--)
	{
		long long number_of_case = 0;
		string str;
		cin >> str;

		vector<vector<int>> v(str.size(), vector<int>(16, 0));


		for (int day = 0; day < str.size(); day++)
		{
			int manager = 1 << (str[day] - 'A'); // �ش� ��Ʈ Ű��
			for (int i = 1; i < 16; i++) // i�� �������� ����� ��
			{
				if (day == 0) //ù ���� ����� �� üũ
				{

					if ((i & manager) != 0 && (i & 1) != 0) // 1���� å���ڿ� A�� �ִٸ�
					{
						v[day][i] = 1;
					}
				}
				else
				{
					if (v[day - 1][i] != 0) // ������ ����� ���� �ִ� ��� �߰��� ����� �� ���
					{
						for (int j = 1; j < 16; j++)
						{
							if ((j & i) != 0 && (j & manager) != 0) // ���� �����ڰ� �ְ� å���ڰ� �ִ� ��� üũ
							{
								v[day][j] += v[day - 1][i]; // ������ ����� ���� �������� ����� ���� ����
								v[day][j] %= 1000000007;
							}
						}
					}
				}

			}

		}

		for (int i = 1; i < 16; i++)
		{
			number_of_case += v[str.size() - 1][i];
			number_of_case %= 1000000007;
		}

		cout << number_of_case;

	}


	return 0;

}

