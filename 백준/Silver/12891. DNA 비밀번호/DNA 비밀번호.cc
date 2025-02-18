#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

int s, p;
unordered_map<char, int> um;
unordered_map<char, int>tmpUm;
bool Is_DNA_Password() // 현재 tmpUm에 담겨있는 비밀번호들의 개수가 요구 사항 이상인지 확인
{
	return tmpUm['A'] >= um['A']
		&& tmpUm['C'] >= um['C']
		&& tmpUm['G'] >= um['G']
		&& tmpUm['T'] >= um['T'];
}

int main()
{

	cin >> s >> p;

	string str;
	cin >> str;

	for (int i = 0;i<p;i++) // 처음 검사 할 위치까지만 미리 담아둠 (슬라이딩 윈도우를 위해서)
	{
		tmpUm[str[i]]++;
	}

	int a, c, g, t;
	cin >> a >> c >> g >> t;
	um['A'] = a;
	um['C'] = c;
	um['G'] = g;
	um['T'] = t;

	int ans = Is_DNA_Password(); // 맨 처음에 가능한지 확인
	int left = 0, right = p;
	while (right<s)
	{
		tmpUm[str[right++]]++; // 다음 위치로 갈 거니까 그 부분 ++
		tmpUm[str[left++]]--; // 이전 위치 개수 --

		if (Is_DNA_Password()) ans++; // 변경됐을 때 비밀번호가 완성되는지 확인
	}

	cout << ans;
	
	return 0;
}
