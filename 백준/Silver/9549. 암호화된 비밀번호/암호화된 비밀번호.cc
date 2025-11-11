#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		string ori, sec;
		cin >> sec >> ori;

		// 원래의 암호에서 사이즈만큼의 구간을 두고
		// 바뀐 암호 그 구간만큼 탐색하면서 있는지를 확인하기
		int size = sec.size();
		int size2 = ori.size();
		// 구간별로 있는 알파벳 넣어두기
		vector<int> vec1(26, 0), vec2(26, 0);
		for (auto& ch : ori) // 기존에 있어야할 알파벳들
		{
			vec1[ch - 'a']++;
		}

		for (int i = 0; i < size2; i++) // 기존 구간까지 검사
		{
			vec2[sec[i] - 'a']++;
		}
		if (vec1 == vec2)
		{
			cout << "YES\n";
			continue;
		}
		bool found = false;
		// 구간만큼 뛰면서 해당 구간에 존재하는지 파악??
		for (int i = size2; i < size; i++)
		{
			vec2[sec[i - size2] - 'a']--;
			vec2[sec[i] - 'a']++;
			if (vec1 == vec2)
			{
				cout << "YES\n";
				found = true;
				break;
			}
		}
		if (!found)
		{
			cout << "NO\n";
		}
	}
	return 0;
}
