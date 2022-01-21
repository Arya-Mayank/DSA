#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int key)
{

    if (root == nullptr)
    {
        return new node(key);
    }

    if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }

    return root;
}

void printInorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

node *findMin(node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

node *deleteNode(node *root, int k)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (k < root->data)
    {
        root->left = deleteNode(root->left, k);
    }
    else if (k > root->data)
    {
        root->right = deleteNode(root->right, k);
    }
    // root's value matches k
    else
    {
        // case 1: leaf node
        if (root->left == nullptr and root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        // case 2: one child
        else if (root->right == nullptr)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else if (root->left == nullptr)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        // case 3: two children
        else
        {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void mirror(node *root){
    if(root == nullptr){
        return;
    }
    else{
        node *temp;
        mirror(root->left);
        mirror(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

}

int main()
{

    node *root = nullptr;
    int arr[] = {10, 6, 12, 5, 8, 14, 7, 13, 15};

    for (int x : arr)
    {
        root = insert(root, x);
    }
    printInorder(root);
    mirror(root);
    cout << endl;
    printInorder(root);

    return 0;
}