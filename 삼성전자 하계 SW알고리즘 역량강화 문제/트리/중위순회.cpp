#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;
int N;
vector<string> v;

void postorder_traverse(int root)
{
	if ((N + 1) > 2 * root)
	{
		postorder_traverse(2 * root);
	}
	cout << v[root];
	if ((N + 1) > (2 * root) + 1)
	{
		postorder_traverse((2 * root) + 1);
	}
}

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> N;
		v.resize(N + 1);
		cin.ignore();

		for (int i = 0; i < N; i++)
		{
			int idx;
			char alph;
			scanf("%d %c", &idx, &alph);
			while (getchar() != '\n');
			v[idx] = alph;
		}

		cout << "#" << test_case << " ";

		postorder_traverse(1);
		cout << '\n';
		v.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}