#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
vector<string> v;
void Fun(string& str)
{
	while (true)
	{
		if (str.size() && str.front() == '0') str.erase(str.begin());
		else break;
	}
	if (str.size() == 0)
		str = "0";
	v.push_back(str);
}

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;

	return a.size() < b.size();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;

		string number;

		for (const auto ch : str)
		{
			if (isdigit(ch))
			{
				number += ch;
			}
			else
			{
				if (number.size())
					Fun(number);
				number = "";
			}
		}

		if (number.size())
			Fun(number);
	}

	sort(v.begin(), v.end(),cmp);

	for (const auto num : v)
	{
		cout << num << "\n";
	}

	return 0;
}