#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{

			char alph;
			int vertex, num1, num2;
			cin >> vertex;

			if (vertex <= n / 2) // n/2보다 작다면 리프노드가 아님
			{
				if (vertex * 2 == n)
					cin >> alph >> num1;
				else
					cin >> alph >> num1 >> num2;

				if (alph >= '0' && alph <= '9') // 리프노드가 아닌데 숫자인 경우
					ans = 0;
			}
			else
			{
				cin >> alph;
				if (!(alph >= '0' && alph <= '9')) // 리프노드인데 숫자가 아닌 경우
					ans = 0;
			}
		}
		cout << '#' << test_case << " " << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
