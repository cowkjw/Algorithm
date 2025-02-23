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

int dp[1001][1001];
int main()
{

	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= (int)str1.size(); i++)
	{
		for (int j = 1; j <= (int)str2.size(); j++)
		{
			if (str1[i - 1] == str2[j - 1]) // 같은 경우에 
			{
				dp[i][j] = dp[i - 1][j - 1] + 1; // 늘려가는 과정
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int idx1 = (int)str1.size(), idx2 = (int)str2.size();
	string ans;
	while (idx1 >= 0 && idx2 >= 0) // 이제 역순으로 찾아감
	{
		if (dp[idx1][idx2] == dp[idx1 - 1][idx2]) // 현재 마지막이랑 A 문자열의 이전이랑 같다면 LCS에 포함되지 않음
		{
			idx1--;
		}
		else if (dp[idx1][idx2] == dp[idx1][idx2 - 1]) // 위와 동일
		{
			idx2--;
		}
		else // idx1-1 idx2-1 과 현재와 같다는 뜻으로 포함된다는 말
		{
			ans += str1[idx1 - 1];
			idx1--;
			idx2--;
		}
	}
	cout << ans.size() << '\n';
	if (ans.size())
	{
		reverse(ans.begin(), ans.end());
		for (const auto ch : ans) cout << ch;
	}
	return 0;
}
