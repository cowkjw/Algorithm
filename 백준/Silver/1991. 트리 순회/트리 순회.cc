#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n;
vector<pair<int, int>> tree[26];

void Preorder(int root)
{
	if (root + 'A' == '.')
		return;
	cout << (char)(root + 'A');
	auto child = tree[root][0];
	int left = child.first;
	int right = child.second;
	if (left + 'A' != '.')
		Preorder(left);
	if (right + 'A' != '.')
		Preorder(right);
}

void Inorder(int root)
{
	auto child = tree[root][0];
	int left = child.first;
	int right = child.second;
	if (left + 'A' != '.')
		Inorder(left);
	cout << (char)(root + 'A');
	if (right + 'A' != '.')
		Inorder(right);
}

void Postorder(int root)
{
	auto child = tree[root][0];
	int left = child.first;
	int right = child.second;
	if (left + 'A' != '.')
		Postorder(left);
	if (right + 'A' != '.')
		Postorder(right);
	cout << (char)(root + 'A');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char root, left, right;

		cin >> root >> left >> right;

		tree[root-'A'].push_back({left - 'A',right - 'A'});
	}

	Preorder(0);
	cout << '\n';
	Inorder(0);
	cout << '\n';
	Postorder(0);
}







