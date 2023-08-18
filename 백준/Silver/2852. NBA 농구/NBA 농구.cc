#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
string ConvertString(int a)
{
	string tmpStr = to_string(a);
	return tmpStr.size() == 1 ? "0" + tmpStr : tmpStr;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	map<int, int> m;
	int a = 0, b = 0;
	int playTime = 48 * 60;
	int prevTime = 0;
	int win = -1;
	while (n--)
	{
		int team;
		string goal;
		cin >> team >> goal;
		int total = stoi(goal.substr(0, 2)) * 60 + stoi(goal.substr(3));

		if (a > b)
		{
			m[1] += total - prevTime;
		}
		else if (a < b)
		{
			m[2] += total - prevTime;
		}

		if (team == 1) a++;
		else b++;
		prevTime = total;
	}

	if (a > b)
	{
		m[1] += playTime - prevTime;
	}
	else if (a < b)
	{
		m[2] += playTime - prevTime;
	}

	string aTime = ConvertString(m[1] / 60) + ":" + ConvertString(m[1] % 60);
	string bTime = ConvertString(m[2] / 60) + ":" + ConvertString(m[2] % 60);
	cout << aTime << '\n' << bTime;


	return 0;
}