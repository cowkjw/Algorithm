#include <string>
#include <vector>

using namespace std;

int answer;
vector<bool> vis(9);
void DFS(const vector<vector<int>>& dungeons, int k, int cnt)
{

	for (int i = 0; i < dungeons.size(); i++)
	{
		if (vis[i] || dungeons[i][0] > k) continue;

		vis[i] = true;
		DFS(dungeons, k - dungeons[i][1], cnt + 1);
		vis[i] = false;
	}
    
    answer = max(answer,cnt);
}

int solution(int k, vector<vector<int>> dungeons) {

	DFS(dungeons, k, 0);

	return answer;
}
