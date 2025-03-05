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
    int n, m, j;
    cin >> n >> m >> j;

    int left = 1;  
    int total_moves = 0;

    while (j--) {
        int apple_pos;
        cin >> apple_pos;

        // 사과가 바구니 범위 내에 있으면 이동 필요 없음
        if (left <= apple_pos && apple_pos <= left + m - 1) 
        {
            continue;
        }

        // 사과가 바구니 왼쪽에 있으면 왼쪽으로 이동
        if (apple_pos < left)
        {
            int moves = left - apple_pos;
            left = apple_pos;
            total_moves += moves;
        }
        // 사과가 바구니 오른쪽에 있으면 오른쪽으로 이동
        else 
        {
            int moves = apple_pos - (left + m - 1);
            left = apple_pos - m + 1;
            total_moves += moves;
        }
    }

    cout << total_moves;
	return 0;
}