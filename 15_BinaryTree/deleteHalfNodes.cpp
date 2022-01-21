#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int d)
    {
        key = d;
        left = right = nullptr;
    }
};

vector<int> solution;

Node *help(Node *root)
{
    // base case
    if (!root)
    {
        return nullptr;
    }

    root->left = help(root->left);
    root->right = help(root->right);

    // left and right subtrees are null, root is leaf node
    if (root->left == nullptr and root->right == nullptr)
    {
        return root;
    }

    // left subtree is empty
    if (root->left == nullptr)
    {
        Node *new_root = root->right;
        free(root);
        return new_root;
    }

    // right subtree is empty
    if (root->right == nullptr)
    {
        Node *new_root = root->left;
        free(root);
        return new_root;
    }
    return root;
}

void fillInorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    fillInorder(root->left);
    solution.push_back(root->key);
    fillInorder(root->right);
}

vector<int> removeHalfNodes(Node *root)
{
    Node *newRoot = help(root);
    fillInorder(newRoot);
    return solution;
}

Node *buildTree()
{

    int d;
    cin >> d;

    if (d == -1)
    {
        return nullptr;
    }

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

int main()
{

    Node *root = buildTree();

    vector<int> ans = removeHalfNodes(root);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
