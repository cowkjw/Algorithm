#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m;
int v[1025];
vector<int> level[11]; // l m r

void go(int start,int end,int depth)
{
	if (start>end) return;
	if (start == end)
	{
		level[depth].push_back(v[start]);
		return;
	}

	int mid = (start + end) / 2;
	level[depth].push_back(v[mid]);

	go(start, mid - 1, depth + 1);
	go(mid + 1, end, depth + 1);

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n; // k

	for (int i = 0; i < (int)pow(2, n) - 1; i++)
	{
		cin >> v[i];
	}

	go(0, (int)pow(2, n) - 1, 1);

	for (int i = 1; i <= n; i++)
	{
		for (auto j : level[i])
		{
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}