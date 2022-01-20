//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string,int> Pokemon;
	map<int,string> PokemonNum;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N + M; i++) 
	{

		if (i <= N)
		{
			string str;
			cin >> str;
			Pokemon.insert(pair<string, int>(str, i));
			PokemonNum.insert(pair<int,string>(i,str));

		}
		else
		{
			string find;
			cin >> find;

			if (!isdigit(find[0]))
			{
				cout<<Pokemon[find]<<"\n";
			}
			else
				cout << PokemonNum[stoi(find)] << "\n";

		}

	}

}

