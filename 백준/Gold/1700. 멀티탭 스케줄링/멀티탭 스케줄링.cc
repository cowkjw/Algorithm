#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
int vis[101];
int arr[101];
int n, k,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n>>k;
	vector<int> v;
	for (int i = 0; i < k; i++) cin >> arr[i];
	for (int i = 0; i < k; i++)
	{
		if (!vis[arr[i]])
		{
			if (v.size() == n)
			{
				int lastIdx = 0, pos;
				for (int _arr : v) // 현재 콘센트 배열 돌기
				{
					int hereIdx = INF;
					for (int j = i + 1; j < k; j++) // 이 다음에 올 활동 순회
					{
						if (arr[j] == _arr) // 만약 지금 꽂혀있는 것과 같은 활동이라면
						{
							hereIdx = j; // 현재 인덱스를 j로 변경
							break;
						}
					}
					if (lastIdx < hereIdx) // 제일 멀리있는 활동으로 설정
					{
						lastIdx = hereIdx;
						pos = _arr; // 바꿀 번호로 변경 
					}
				}

				vis[pos] = 0; // 콘센트 뽑음
				cnt++;
				v.erase(find(v.begin(), v.end(), pos));

			}
		v.push_back(arr[i]);
		vis[arr[i]] = 1;
		}
	}

	cout << cnt;
	return 0;
}
