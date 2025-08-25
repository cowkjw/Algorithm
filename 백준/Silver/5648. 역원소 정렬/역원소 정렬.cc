#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> vec;
	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		vec.push_back(num);
	}
	// 10으로 나누는데 나머지가 0이다?? 그럼 뒤집었을 때 어차피 0으로 바꿔야함

	for (auto& num : vec)
	{
		while (num % 10 == 0)
		{
			num /= 10;
		}
		string s = to_string(num);

		reverse(s.begin(), s.end());
		num = stoll(s);
	}

	sort(vec.begin(), vec.end());
	for (auto num : vec)
	{
		cout << num << "\n";
	}
	return 0;
}