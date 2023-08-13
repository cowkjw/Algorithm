#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

map<char, int> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	while (n--)
	{
	string str;
	cin >> str;
	m[str[0]]++;
	}

	string answer;
	for (const auto& ch : m)
	{
		if (ch.second >= 5) answer += ch.first;
	}

	if (answer.size() == 0) cout << "PREDAJA";
	else cout << answer;

	return 0;
}
