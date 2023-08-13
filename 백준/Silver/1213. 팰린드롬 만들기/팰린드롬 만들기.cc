#include <bits/stdc++.h>
#define INF -987654321
using namespace std;

string s, ret;
int cnt[26], flag;
char mid;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (char a : s)cnt[a - 'A']++;
	for (int i = 26; i >= 0; i--)
	{
		if (cnt[i]) 
		{
			if (cnt[i] & 1)
			{
				mid = char(i + 'A'); flag++;
				cnt[i]--;
			}
			if (flag == 2)break;
			for (int j = 0; j < cnt[i]; j += 2) 
			{
				ret = char(i + 'A') + ret;
				ret += char(i + 'A');
			}
		}
	}
	if (mid)ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2)cout << "I'm Sorry Hansoo\n";
	else cout << ret << "\n";
	return 0;
}