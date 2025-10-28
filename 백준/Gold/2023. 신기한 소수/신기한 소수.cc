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
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321
int n, m, d;
vector<int> ans;

bool IsPrime(int num)
{
	if (num < 2) return false;     // 0, 1은 소수가 아님
	if (num == 2) return true;     // 2는 유일한 짝수 소수
	if (num % 2 == 0) return false; // 2 제외한 짝수는 소수가 아님

	for (int i = 3; i * i <= num; i += 2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void Back(int cnt, string num)
{
	int tmpNum = stoi(num);
	if (!IsPrime(tmpNum)) return;
	if (n == cnt)
	{

		ans.push_back(stoi(num));
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		Back(cnt + 1, num + to_string(i));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		Back(1, to_string(i));	
	}
	for (auto num : ans)
	{
		cout << num << '\n';
	}
	return 0;
}
