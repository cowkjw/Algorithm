#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;


int dpMax[4];
int dpMin[4];
int board[4];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	

	cin >> dpMax[1] >> dpMax[2] >> dpMax[3];
	
	dpMin[1] = dpMax[1];
	dpMin[2] = dpMax[2];
	dpMin[3] = dpMax[3];

	for (int i = 1; i <n; i++)
	{
		cin >> board[1] >> board[2] >> board[3];	
		int temp1 = dpMax[1]; // 값이 바뀌기 때문에 temp에 저장
		int temp2 = dpMax[2];
		int temp3 = dpMax[3];

		dpMax[1] = max(dpMax[1], dpMax[2]) + board[1];
		dpMax[2]= max(max(temp1, temp2), temp3) + board[2];
		dpMax[3] = max(temp2, temp3) + board[3];

		temp1 = dpMin[1];
		temp2 = dpMin[2];
		temp3 = dpMin[3];

		dpMin[1] = min(dpMin[1], dpMin[2]) + board[1];
		dpMin[2] = min(min(temp1, temp2), temp3) + board[2];
		dpMin[3] = min(temp2, temp3) + board[3];


	}
	int mx = max(max(dpMax[1], dpMax[2]), dpMax[3]);
	int mn = min(min(dpMin[1], dpMin[2]), dpMin[3]);

	cout << mx << " " << mn;

}






