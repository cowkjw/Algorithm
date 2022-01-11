#include <iostream>
using namespace std;



int main()
{
	string alpha;
	int cnt = 0;

	cin >> alpha;
	for (int i = 0; i < alpha.size(); i++)
	{
		cnt++;
		if (alpha[i] == '=')
		{
			if (alpha[i - 1] == 'c' || alpha[i - 1] == 'z' || alpha[i - 1] == 's' || (alpha[i - 1] == 'z' && alpha[i - 2] == 'd'))
			{
				if ((alpha[i - 1] == 'z' && alpha[i - 2] == 'd'))
					cnt -= 2;
				else
					cnt--;
			}

		}
		else if (alpha[i] == '-')
		{
			if (alpha[i - 1] == 'c' || alpha[i - 1] == 'd')
			{
				cnt--;
			}
		}
		else if (alpha[i] == 'j')
		{
			if (alpha[i - 1] == 'n' || alpha[i - 1] == 'l')
			{
				cnt--;
			}
		}

	}
	cout << cnt;
	return 0;
}
