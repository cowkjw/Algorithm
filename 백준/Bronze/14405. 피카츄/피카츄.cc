#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m, t;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	int size = str.size();
	bool flag = 0;

	for (int i = 0; i < size;i++)
	{
		if (i < str.size() - 1 && str.substr(i, 2) == "pi" || str.substr(i, 2) == "ka") i += 1;
		else if (i < str.size() - 2 && str.substr(i, 3) == "chu") i += 2;
		else flag = 1;
	}
	if (!flag)cout << "YES";
	else cout << "NO";
	return 0;
}