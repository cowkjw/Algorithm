#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321


int A[11][11], B[11][11];
int n, m, k;
int dx[]{ -1,-1,-1,0,0,1,1,1 };
int dy[]{ -1,0,1,-1,1,-1,0,1 };
vector<int> tree[11][11];

void SpringSummer()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (tree[i][j].empty()) continue;
			sort(tree[i][j].begin(), tree[i][j].end());
			vector<int> alive;
			int dead = 0;

			for (int age : tree[i][j])
			{
				if (age <= B[i][j])
				{
					B[i][j] -= age;
					alive.push_back(age + 1);
				}
				else
				{
					dead += age / 2;
				}
			}

			tree[i][j] = alive; // 살아있는 나무를 업데이트함
			B[i][j] += dead; // 죽은 나무의 양분을 땅에 추가함
		}
	}
}

void Fall()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (tree[i][j].empty()) continue;
			for (int year : tree[i][j])
			{
				if (year % 5 == 0)
				{
					for (int k = 0; k < 8; k++)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (nx<=0 || ny<=0 || nx>n || ny>n) continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

void Winter()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			B[i][j] += A[i][j];
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> A[i][j];
			B[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> y >> x >> z;
		tree[y][x].push_back(z);
	}

	while (k--)
	{
		SpringSummer();
		Fall();
		Winter();
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (tree[i][j].size()) ans += tree[i][j].size();
		}
	}
	cout << ans;
	return 0;
}
