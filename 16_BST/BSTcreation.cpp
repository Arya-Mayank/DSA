#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }

    if (key <= root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

bool search(Node *root, int key)
{

    // base
    // element not found
    if (root == nullptr)
    {
        return false;
    }

    // element found
    if (key == root->key)
    {
        return true;
    }

    if (key < root->key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

Node *min(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *remove(Node *root, int key)
{

    if (root == nullptr)
    {
        return nullptr;
    }

    else if (key < root->key)
    {
        root->left = remove(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = remove(root->right, key);
    }
    else
    {
        // value of node matches key

        // 1. leaf Node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }

        // 2. single child
        else if (root->left == nullptr)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // 3. two children
        else
        {
            Node *temp = min(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    return root;
}
vector<int> InorderVector;

void printInorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInorder(root->left);
    // cout << " " << root->key << ", ";
    InorderVector.push_back(root->key);
    printInorder(root->right);
}

void printInRange(Node *root, int k1, int k2)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->key >= k1 && root->key <= k2)
    {
        printInRange(root->left, k1, k2);
        cout << root->key << " ";
        printInRange(root->right, k1, k2);
    }
    else if (root->key < k1)
    {
        printInRange(root->right, k1, k2);
    }
    else
    {
        printInRange(root->left, k1, k2);
    }
}

vector<int> path;
void RootToLeaf(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    // leaf node
    if (root->left == nullptr && root->right == nullptr)
    {
        for (int x : path)
        {
            cout << x << " -> ";
        }
        cout << root->key << endl;
        return;
    }
    else
    {
        path.push_back(root->key);
    }

    RootToLeaf(root->left);
    RootToLeaf(root->right);
    path.pop_back();
}

bool isSorted(vector<int> arr)
{
    bool ans = true;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            ans = false;
        }
    }
    return ans;
}


bool isBST(Node *root)
{

    printInorder(root);
    return isSorted(InorderVector);
}

int main()
{

    // root of the BST initially null
    Node *root = nullptr;

    // array to read and feed values from
    vector<int> arr = {17, 10, 26, 12, 43, 9, 5};

    for (int x : arr)
    {
        root = insert(root, x);
    }

    cout << isBST(root);

    // RootToLeaf(root);

    // printInRange(root, 8, 24);

    
    // cout << endl << search(root, 9);

    // Node * newRoot = remove(root, 10);
    // cout<<endl;
    // printInorder(newRoot);

    return 0;
}