#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, boom;
	cin >> str;
	cin >> boom;
	string ret;
	for (char ch : str)
	{
		ret += ch;
		if (ret.size() >= boom.size() && ret.substr(ret.size() - boom.size(), boom.size()) == boom)
		{
			ret.erase(ret.size() - boom.size(), boom.size());
		}
	}
	if (ret.size()) cout << ret;
	else cout << "FRULA";
	return 0;
}