#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <numeric>
using namespace std;
#define INF 987654321

vector<int> ans;
struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
	int val = 0;
};

struct Tree
{
	Node* root = nullptr;
	~Tree() { Release(root); }

	void Release(Node* node)
	{
		if (node)
		{
			Release(node->left);
			Release(node->right);
			delete node;
			node = nullptr;
		}
	}

	void PreOrder(const Node* node)
	{
		if (node == nullptr) return;

		PreOrder(node->left);
		PreOrder(node->right);
		ans.push_back(node->val);
	}

	void Insert(int val,Node* node = nullptr)
	{
		if (node == nullptr)
		{
			root = new Node;
			root->val = val;
			return;
		}

		if (node->val < val)
		{
			if (node->right)
			{
				Insert(val, node->right);
			}
			else
			{
				node->right = new Node;
				node->right->val = val;
			}
		}
		else
		{
			if (node->left)
			{
				Insert(val, node->left);
			}
			else
			{
				node->left = new Node;
				node->left->val = val;
			}
		}
	}

};
int main()
{
	int n;
	Tree tree;
	while (cin >> n)
	{
		tree.Insert(n,tree.root);
	}
	tree.PreOrder(tree.root);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
