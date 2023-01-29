#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	vector<string>arr{ "black","brown","red","orange","yellow","green","blue","violet","grey","white" };

	string ans;

	for (int i = 0; i < 3; i++)
	{
		string str;
		cin >> str;
		if (i == 2)
		{
			ans = to_string(static_cast<long long>((stoi(ans))*pow(10,(find(arr.begin(), arr.end(), str)-arr.begin()))));
		}
		else
		{
			ans += to_string((find(arr.begin(), arr.end(), str) - arr.begin()));
		}

	}

	cout << ans;


	return 0;
}