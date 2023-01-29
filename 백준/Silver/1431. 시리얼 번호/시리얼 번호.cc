#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;

int CountNumber(const string& str)
{
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i])) sum += str[i] - '0';
	}
	return sum;
}

int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<string> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		if (a.size() != b.size()) return  a.size() < b.size();
		else if (CountNumber(a) != CountNumber(b)) return CountNumber(a) < CountNumber(b);
		else return a < b;
		});

	for (const auto& str : v)
	{
		cout << str << '\n';
	}

	return 0;
}