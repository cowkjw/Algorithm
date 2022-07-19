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
			int manager = 1 << (str[day] - 'A'); // 해당 비트 키기
			for (int i = 1; i < 16; i++) // i는 참여자의 경우의 수
			{
				if (day == 0) //첫 날의 경우의 수 체크
				{

					if ((i & manager) != 0 && (i & 1) != 0) // 1일차 책임자와 A가 있다면
					{
						v[day][i] = 1;
					}
				}
				else
				{
					if (v[day - 1][i] != 0) // 전날의 경우의 수가 있는 경우 추가로 경우의 수 계산
					{
						for (int j = 1; j < 16; j++)
						{
							if ((j & i) != 0 && (j & manager) != 0) // 어제 참여자가 있고 책임자가 있는 경우 체크
							{
								v[day][j] += v[day - 1][i]; // 전날의 경우의 수를 다음날의 경우의 수에 더함
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

