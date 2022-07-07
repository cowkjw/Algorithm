#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string>  v;

	string input;
	cin >> input;
	
	for (int i = 0; i < input.size(); i++)
	{
		v.emplace_back(input.substr(i));
	}

	sort(v.begin(), v.end());
	
	for (auto i : v)
		cout << i <<"\n";

	return 0;

}

