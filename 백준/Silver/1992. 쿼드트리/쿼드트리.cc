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

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
vector<string> board;
string ans;
void solve(int y, int x, int size) 
{
    // 첫 칸 기준
    char first = board[y][x];
    bool same = true;

    // 이 영역 전체가 같은지 검사
    for (int i = y; i < y + size; i++) 
    {
        for (int j = x; j < x + size; j++) 
        {
            if (board[i][j] != first)
            {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same)
    {
        ans += first;
        return;
    }

    // 다르면 4개로 분할
    ans += '(';

    int half = size / 2;
    solve(y, x, half);  // 왼쪽 위
    solve(y, x + half, half); // 오른쪽 위
    solve(y + half, x, half); // 왼쪽 아래
    solve(y + half, x + half, half); // 오른쪽 아래

    ans += ')';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}
    solve(0, 0, n);
    cout << ans;
	return 0;
}
