#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


string string_add(string a, string b)
{
	int sum = 0;
	string ret;
	while (a.size() || b.size() || sum)
	{
		if (a.size()) // a의 1의 자리수들 더하기
		{
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size()) // b의 1의 자리수들 더하기
		{
			sum += b.back() - '0';
			b.pop_back();
		}
		ret += (sum % 10) + '0'; // sum의 1의 자리 더하기
		sum /= 10; // sum의 10의 자리수
	}
	reverse(ret.begin(), ret.end());// 뒤에서부터 더했으니 반전 시킴
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	cout<<string_add(a, b);
	return 0;
}