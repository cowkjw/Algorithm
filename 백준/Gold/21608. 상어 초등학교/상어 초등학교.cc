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



int n;
int board[21][21]; // 0이면 빈칸
struct Node
{
	list<pair<int, int>> edges; // 나의 인접한 칸 멘허튼 거리 공식으로
	vector<int> like; // 좋아하는 학생들
	pair<int, int> pos; // 내 위치
	int number = 0; // 내 번호
	void init(int r, int c)
	{
		pos = { r,c };
		board[r][c] = number;
		Renew();
	}
	void Renew()
	{
		edges.clear();
		int r = pos.first;
		int c = pos.second;
		if (r - 1 >= 0 && board[r - 1][c] == 0) edges.push_back({ r - 1,c });
		if (r + 1 < n && board[r + 1][c] == 0) edges.push_back({ r + 1,c });
		if (c - 1 >= 0 && board[r][c - 1] == 0) edges.push_back({ r,c - 1 });
		if (c + 1 < n && board[r][c + 1] == 0) edges.push_back({ r,c + 1 });
	}
};

int CntEmpty(int r, int c)
{
	int cnt = 0;
	if (r - 1 >= 0 && board[r - 1][c] == 0) cnt++;
	if (r + 1 < n && board[r + 1][c] == 0) cnt++;
	if (c - 1 >= 0 && board[r][c - 1] == 0) cnt++;
	if (c + 1 < n && board[r][c + 1] == 0) cnt++;
	return cnt;
}
// 좋아하는 학생 인접 개수 계산
int CntLiked(int r, int c, const vector<int>& likes)
{
	int cnt = 0;
	if (r - 1 >= 0)
	{
		for (int like : likes)
		{
			if (board[r - 1][c] == like) 
			{
				cnt++;
				break; 
			}
		}
	}
	if (r + 1 < n)
	{
		for (int like : likes)
		{
			if (board[r + 1][c] == like) 
			{ 
				cnt++;
				break; 
			}
		}
	}
	if (c - 1 >= 0)
	{
		for (int like : likes)
		{
			if (board[r][c - 1] == like)
			{
				cnt++;
				break; 
			}
		}
	}
	if (c + 1 < n) 
	{
		for (int like : likes) 
		{
			if (board[r][c + 1] == like) 
			{ 
				cnt++; 
				break;
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<Node> students(n * n + 1);
	vector<int> order; // 입력 순서 저장

	for (int i = 0; i < n * n; i++)
	{
		int num;
		cin >> num;
		order.push_back(num); // 순서 저장
		students[num].number = num;
		for (int j = 0; j < 4; j++)
		{
			int like;
			cin >> like;
			students[num].like.push_back(like);
		}
	}

	unordered_set<int> exist;

	// 입력 순서대로 처리
	for (int studentNum : order)
	{
		Node& student = students[studentNum];

		// 모든 빈 칸에 대해 최적 위치 찾기
		int maxLiked = -1;
		int maxEmpty = -1;
		pair<int, int> best = { -1, -1 };

		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				if (board[r][c] != 0) continue; // 이미 차있으면 패스

				int likedCnt = CntLiked(r, c, student.like);
				int emptyCnt = CntEmpty(r, c);

				bool update = false;

				// 조건 1: 좋아하는 학생 인접 개수
				if (likedCnt > maxLiked) 
				{
					update = true;
				}
				// 조건 2: 빈 칸 개수
				else if (likedCnt == maxLiked && emptyCnt > maxEmpty) 
				{
					update = true;
				}
				// 조건 3,4: 행, 열 번호
				else if (likedCnt == maxLiked && emptyCnt == maxEmpty) 
				{
					if (best.first == -1 || r < best.first || (r == best.first && c < best.second)) 
					{
						update = true;
					}
				}

				if (update)
				{
					maxLiked = likedCnt;
					maxEmpty = emptyCnt;
					best = { r, c };
				}
			}
		}

		student.init(best.first, best.second);
		exist.insert(student.number);
	}
	// 만족도 계산
	int ans = 0;
	for (int i = 1; i <= n * n; i++)
	{
		int r = students[i].pos.first;
		int c = students[i].pos.second;
		int cnt = 0;
		for (auto& like : students[i].like)
		{
			if (r - 1 >= 0 && board[r - 1][c] == like) cnt++;
			if (r + 1 < n && board[r + 1][c] == like) cnt++;
			if (c - 1 >= 0 && board[r][c - 1] == like) cnt++;
			if (c + 1 < n && board[r][c + 1] == like) cnt++;
		}
		if (cnt == 0) ans += 0;
		else if (cnt == 1) ans += 1;
		else if (cnt == 2) ans += 10;
		else if (cnt == 3) ans += 100;
		else if (cnt == 4) ans += 1000;
	}
	cout << ans;
    return 0;
}