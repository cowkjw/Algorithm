#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
using namespace std;

int n, m;
int parent[1000001];

int Find_Parent(int a)
{
	if (parent[a] == a)
		return a;

	// 경로 단축 루트 노드로 연결 시키기
	return parent[a] = Find_Parent(parent[a]);
}
void Uni(int a, int b)
{
	a = Find_Parent(a);
	b = Find_Parent(b);

	if (a != b)
		parent[a] = b; // a의 루트를 b에 연결
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int x, a, b;
		cin >> x >> a >> b;

		if (x == 0)
		{
			Uni(a, b);
		}
		else
		{
			if (Find_Parent(a) == Find_Parent(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}