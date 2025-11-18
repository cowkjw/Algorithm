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
vector<int> graph[11];
int vis[11];
int student[11];

int ans = -1;
vector<vector<int>> score(6, vector<int>(3, 0));
vector<pii> games;
bool Back(int idx) 
{
	if (idx == 15)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (score[i][j]) return false;
			}
		}

		return true;
	}

	int a = games[idx].first;
	int b = games[idx].second;

	// 승, 무 , 패

	if (score[a][0] > 0 && score[b][2]>0)
	{
		score[a][0]--;
		score[b][2]--;
		if (Back(idx + 1))
			return true;
		score[a][0]++;
		score[b][2]++;
	}


	if (score[a][1] > 0 && score[b][1]>0)
	{
		score[a][1]--;
		score[b][1]--;
		if (Back(idx + 1))
			return true;
		score[a][1]++;
		score[b][1]++;
	}


	if (score[a][2] > 0 && score[b][0]>0)
	{
		score[a][2]--;
		score[b][0]--;
		if (Back(idx + 1))
			return true;
		score[a][2]++;
		score[b][0]++;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 각 팀 별로 결과는 5개가 나올 수 있음
	//

	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			games.push_back({ i,j });
		}
	}
	for (int i = 0; i < 4; i++)
	{
		score = vector<vector<int>>(6, vector<int>(3, 0));
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cin>>score[j][k];
			}
		}
		cout << Back(0) << " ";
	}

	return 0;
}
