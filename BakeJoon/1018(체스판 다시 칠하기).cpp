#include <bits/stdc++.h>
using namespace std;

string board[51];
string WB[8]
{
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
};
string BW[8]
{
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
};


int FindWB(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[x+i][y+j] != WB[i][j])
				cnt++;
	return cnt;
}


int FindBW(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[x + i][y + j] != BW[i][j])
				cnt++;
	return cnt;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	int N, M;
	int ans = 2501;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			char temp;
			cin >> temp;
			board[i] += temp;
		}

	for(int i = 0;i<=N-8;i++)
		for (int j = 0; j <=M - 8; j++)
		{
			int tMin = min(FindBW(i, j), FindWB(i, j));
			ans = min(ans, tMin);
		}
	cout << ans;


	return 0;

}

