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


struct Problem
{
	int cnt; // 제출 횟수
	int score;// 점수
};
struct Team
{
	int id;
	vector<Problem> problem; //점수, 제출 횟수
	int score;
	int last;
	int cnt = 0;
	void CalculScore()
	{
		for (auto& pro : problem)
		{
			score += pro.score;
		}
	}
	bool operator<(const Team& t)
	{
		if (t.score == this->score)
		{
			if (t.cnt == this->cnt)
			{
				return  this->last < t.last;
			}
			return this->cnt < t.cnt;
		}
		return this->score > t.score;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int k, id, m;
		cin >> n >> k >> id >> m;
		//최종 점수가 같은 경우, 풀이를 제출한 횟수가 적은 팀의 순위가 높다.
		//최종 점수도 같고 제출 횟수도 같은 경우, 마지막 제출 시간이 더 빠른 팀의 순위가 높다.
		vector<Team> team(n+1);
		for (int i = 1; i <= n; i++) 
		{
			team[i].id = i;
			team[i].problem.resize(k + 1);
		}
		for (int log = 0; log < m; log++)
		{
			int i, j, s;
			cin >> i >> j >> s; // ID,문제 번호,점수
			team[i].problem[j].score = max(team[i].problem[j].score, s);
			team[i].cnt++;
			team[i].last = log+1;
		}
		for (auto& t : team) t.CalculScore();
		sort(team.begin()+1, team.end());

		for (int i = 1; i <= n; i++)
		{
			if (id == team[i].id)
			{
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}
