#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321


struct Info
{
	string name;
	int days;
};

vector<string> Split(string str, string target)
{
	int pos = 0;
	vector<string> temp;
	string sp;
	int idx = 0;
	while ((pos=str.find(target))!=-1)
	{
		temp.push_back(str.substr(0, pos));
		str.erase(0, pos + target.length());
	}
	temp.push_back(str);
	return temp;
}

int Convert(vector<string> tmp)
{
	int ret = 0;

	ret += stoi(tmp[1]) + stoi(tmp[2]) * 31 + stoi(tmp[3]) * 365;
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<Info>v;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		vector<string> tmp = Split(str, " ");
		int t = Convert(tmp);
		v.push_back({ tmp[0],t });
	}
	sort(v.begin(), v.end(), [](Info a, Info b) {
		return a.days < b.days;
		});
	cout << v.back().name << '\n' << v.front().name;
	return 0;
}
