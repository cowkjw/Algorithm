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


int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> vec(n + 1);
    vector<int> dp1(n + 1, 1); // 앞에서부터 증가하는 부분 수열
    vector<int> dp2(n + 1, 1); // 뒤에서부터 증가하는 부분 수열 

    for (int i = 1; i <= n; i++) 
    {
        cin >> vec[i];
    }

    // 앞에서부터 증가하는 부분 수열 DP
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++) 
        {
            if (vec[j] < vec[i])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    // 뒤에서부터 증가하는 부분 수열 DP 
    for (int i = n; i >= 1; i--) 
    {
        for (int j = n; j > i; j--) 
        {
            if (vec[j] < vec[i]) 
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    // 최대 바이토닉 부분 수열 길이 계산
    int maxLength = 0;
    for (int i = 1; i <= n; i++) 
    {
		maxLength = max(maxLength, dp1[i] + dp2[i] - 1); // -1은 중복 제거
    }

    cout << maxLength ;
	return 0;
}