#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
char arr[200001];
string str;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> str;

	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(') s.push(i);
		else if (s.size())
		{
			arr[i] = arr[s.top()] = 1;
			s.pop();
		}
	}
	int cnt = 0;
	int ret =0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i])
		{
			cnt++;
			ret = max(ret, cnt);
		}
		else cnt = 0;
	}
	cout << ret;
	return 0;
}