#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int v, e;
int parent[1000001];

int findParent(int x) {

	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}


void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	while (e--)
	{

		int cmd, a, b;

		cin >> cmd >> a >> b;
		if (cmd == 0)
		{
			unionParent(a, b);
		}
		else if (cmd == 1)
		{
			if (findParent(a) == findParent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

}





