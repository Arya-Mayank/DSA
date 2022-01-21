#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string data;
    Node *left;
    Node *right;

    Node(string d)
    {
        data = d;
        left = right = nullptr;
    }
};

Node *buildTree()
{
    string d;
    cin >> d;

    if (d == "-1")
    {
        return nullptr;
    }

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}




int evalTree(Node *root)
{
    // case 1: empty tree
    if(!root){
        return 0;
    }

    //case 2: leaf node
    if(!root->left and !root->right){
        return stoi(root->data);
    }

    //if node is not empty and not a leaf node
    //continue to check left and right subtree
    int l_val = evalTree(root->left);
    int r_val = evalTree(root->right);

    if(root->data == "+"){
        return l_val + r_val;
    }
    if(root->data =="-"){
        return l_val - r_val;
    }
    if(root->data == "*"){
        return l_val * r_val;
    }
    return l_val/r_val;
}

int main()
{
    Node * root = buildTree();

    cout << evalTree(root);

    return 0;
}