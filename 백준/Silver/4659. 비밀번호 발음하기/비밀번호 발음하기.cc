#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<string> vowel{"a", "e", "o", "u", "i"};
	while (true)
	{
		string str;
		cin >> str;
		if (str == "end") break;
		bool flag = false;
		for (const auto& ch : vowel)
		{
			if (str.find(ch) != -1)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "<" + str + ">" + " is not acceptable.\n";
			continue;
		}

		if (str.size() == 1)
		{
			cout << "<" + str + ">" + " is acceptable.\n";
			continue;
		}

		int cntVowel = 0;
		int cntConsonant = 0;
		char prevCh = str[0];
		bool flag2 = true;
		for (int i = 1; i <= str.size(); i++)
		{
			if (prevCh == 'a' || prevCh == 'e' || prevCh == 'o' || prevCh == 'u' || prevCh == 'i')
			{
				cntVowel++;
				cntConsonant = 0;
			}
			else
			{
				cntVowel = 0;
				cntConsonant++;
			}
			if (cntVowel == 3 || cntConsonant == 3)
			{
				cout << "<" + str + ">" + " is not acceptable.\n";
				flag2 = false;
			}
			if (i == str.size())
			{
				break;
			}
			if (prevCh == str[i])
			{
				if ((prevCh != 'e' && str[i] != 'e') && (prevCh != 'o' && str[i] != 'o')) // 연속인데 ee,oo가 아닐 때
				{
					cout << "<" + str + ">" + " is not acceptable.\n";
					flag2 = false;
					break;
				}
			
			}
			prevCh = str[i];
		}

		if (flag2)
		{
			cout << "<" + str + ">" + " is acceptable.\n";
		}
	}


	return 0;
}