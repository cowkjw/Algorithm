#include <iostream>
using namespace std;


bool check(string str)
{

	bool alph[26]{ false };
	bool isGroup = true;
	for (int i = 0; i < str.length(); i++)
	{

		if (!alph[str[i] - 'a'])
		{
			alph[str[i] - 'a'] = true;
		}
		else if (i != 0)
		{

			if (str[i] == str[i - 1])
			{
				isGroup = true;
			}
			else
			{
				return false;
			}

		}

	}

	if (isGroup)
		return true;

}

int main()
{
	int N;
	int cnt = 0;
	string str;

	cin >> N;

	for (int i = 0; i < N; i++)
	{

		cin >> str;

		if (check(str))
		{
			cnt++;
		}

	}
	cout << cnt;



	return 0;
}


