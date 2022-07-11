#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v;
	int N;
	cin >> N;

	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		v.push_back(str);
	}

	while (true)
	{
		set<string>s;
		for (int i = 0; i < v.size(); i++)
		{
			s.insert(v[i].substr(0, cnt));
		}
		if (s.size() == v.size())
			break;
		else
			cnt++;

	}

	cout << cnt;


	return 0;

}

