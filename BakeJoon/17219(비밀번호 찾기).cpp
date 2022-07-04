#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, string> m;
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{

		string site, password;
		cin >> site >> password;

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







