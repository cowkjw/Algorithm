#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;
int water[101][101];
int dp[101][101];
int go(int y, int x, int m, int n)
{
	if (y > n || x > m) return 0;
	if (water[y][x]) return 0;
	if (y == n && x == m) return 1;

	if (dp[y][x]) return dp[y][x];

	dp[y][x] += ((go(y + 1, x, m, n) + go(y, x + 1, m, n))) % mod;

	return dp[y][x];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto puddle : puddles)
    {
        water[puddle[1]][puddle[0]] = 1;
    }
    int answer = go(1,1,m,n);
    return answer;
}