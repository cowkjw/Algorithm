#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, string> m;
	int N, M;

	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		string input;
		string site, password;
		getline(cin, input);
		int idx = input.find(" ");

		site = input.substr(0, idx);
		password = input.substr(idx+1);

		m[site] = password;

	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		cout << m[input] << "\n";
	}



	return 0;

}







