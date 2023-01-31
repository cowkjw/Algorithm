#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;


int n, c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end()); // 이진탐색을 위한 정렬

	int start = 1; // 집이 2개 이상이니까 최소 거리는 1
	int end = v.back() - v.front(); // 끝집과 처음 집 거리 (최대 거리)
	int ans = 0; 
	while (start <= end)
	{
		int pos = v.front(); // 처음 공유기 위치 (처음부터 설치해야함)
		int mid = (start + end) / 2; // 공유기 설치 간격
		int cntRouter = 1; 
		for (int i = 1; i < n; i++) // 왼쪽부터 순차 탐색
		{
			if (v[i] >= pos + mid) // 범위 확인
			{
				cntRouter++; // 설치된 공유기
				pos = v[i]; // 설치된 곳으로 공유기 위치 변경
			}
		}
		if (cntRouter >= c) // c개 이상 설치
		{
			ans = mid; // 일단 최대한 많이 설치된 간격으로 
			start = mid + 1; // 간격 늘리기 ( 최적의 범위를 구하기 위해서)
		}
		else
		{
			end = mid - 1; // 너무 적게 설치 되었기때문에 공유기 간 범위를 줄임
		}

	}
	cout << ans;
	return 0;
}
