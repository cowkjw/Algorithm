#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    Node() : data({ -1,-1 }), left(nullptr), right(nullptr) {}
    Node(const pair<int, int>& _data) : data(_data), left(nullptr), right(nullptr) {}
    pair<int, int> data;
    Node* left;
    Node* right;
};

struct Tree
{
    Tree() : root(new Node) {}
    ~Tree()
    {
        Release(root);
    }
    void Insert(Node* node, pair<int, int> _data)
    {
        if (node == nullptr) return;

        if (node->data.first < _data.first)
        {
            if (node->right)
            {
                Insert(node->right, _data);
            }
            else
            {
                node->right = Create(_data);
            }
        }
        else if (node->data.first > _data.first)
        {
            if (node->left)
            {
                Insert(node->left, _data);
            }
            else
            {
                node->left = Create(_data);
            }
        }
    }

    void Order(vector<vector<int>>& ans, Node* node)
    {
        if (node == nullptr) return;
        
        ans[0].push_back(node->data.second);
        Order(ans, node->left);
        Order(ans, node->right);
        ans[1].push_back(node->data.second);
    }

    Node* Create(const pair<int, int>& _data)
    {
        return new Node(_data);
    };

    void Release(Node* node)
    {
        if (node == nullptr) return;

        Release(node->left);
        Release(node->right);

        delete node;
    }
    Node* root;
};


bool compare(const vector<int>& a, const vector<int>& b)
{
    if (a[1] != b[1]) return a[1] > b[1];
    return a[0] < b[0];
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<vector<int>> treeNode;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        treeNode.push_back({ x,y,i + 1 });
    }
    sort(treeNode.begin(), treeNode.end(), compare);

    Tree tree;
    tree.root->data = { treeNode[0][0],treeNode[0][2] };

    for (int i = 1; i < treeNode.size(); i++)
    {
        tree.Insert(tree.root, { treeNode[i][0],treeNode[i][2] });
    }
    tree.Order(answer,tree.root);
    return answer;
}
