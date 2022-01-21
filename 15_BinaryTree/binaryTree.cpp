#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

Node *buildTree()
{

    int data;
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    Node *n = new Node(data);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void printPreorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";

    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPostorder(Node *root)
{

    if (root == nullptr)
    {
        return;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

// i/p: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// preorder o/p : 1 2 4 5 7 3 6
// inorder o/p: 4 2 7 5 1 3 6
// postorder o/p : 4 7 5 2 6 3 1

void levelOrderPrint(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();

        if (temp == nullptr)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}

int heightOfTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int h1 = heightOfTree(root->left);
    int h2 = heightOfTree(root->right);
    return 1 + max(h1, h2);
}

vector<int> printKthLevel(Node *root, int k)
{
    queue<Node *> q;
    vector<int> sol;

    if (k == 0)
    {
        sol.push_back(root->data);
        return sol;
    }

    q.push(root);
    q.push(nullptr);
    int l = 0;

    while (!q.empty())
    {
        Node *current = q.front();

        if (current == nullptr)
        {
            q.pop();
            l++;

            if (l == k)
            {
                while (!q.empty())
                {
                    sol.push_back(q.front()->data);
                    q.pop();
                }
                return sol;
            }
            else
            {
                if (!q.empty())
                {
                    q.push(nullptr);
                }
            }
        }
        else
        {
            q.pop();
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
    }
}

int sumBT(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int sum=0;
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        sum+= temp->data;
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }

    return sum;
}

// -------Diameter of BT
int diameterBT(Node * root){

    //base case
    if(root == nullptr){
        return 0;
    }

    //rec case
    int h1 = heightOfTree(root->left);
    int h2 = heightOfTree(root->right);

    int d1 = h1+h2;
    int d2 = diameterBT(root->left);
    int d3 = diameterBT(root->right);

    return max(d1,max(d2,d3));
}

// ------------ Optimised Diameter of BT

class HDpair{
    public: 
    int height;
    int diameter;
};

HDpair OptDiameter(Node *root){
    HDpair p;
    
    //base case 
    if(root == nullptr){
        p.height = 0;
        p.diameter =0;
        return p;
    }

    // otherwise
    //compute height and diameter of sub trees
    HDpair Left = OptDiameter(root->left);
    HDpair Right = OptDiameter(root->right);

    //calculate current root node's height
    p.height = max(Left.height, Right.height) +1;

    //calculate current root node's diameter
    int d1 = Left.height + Right.height;
    int d2 = Left.diameter;
    int d3 = Right.diameter;

    p.diameter = max(d1, max(d2,d3));

    return p;
}

int minDepth(Node * root){
    //base case 
    if(root == nullptr){
        return 0;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    return max(left, right)+1;

}

bool isMirror(Node * root1, Node * root2){

    //base case
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }

    if(root1->data == root2->data){
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }

    return false;
}

bool isSymmetric(Node* root) {
        return isMirror(root, root);
}

int main()
{
    // i/p: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node *root = buildTree();

    cout << "Diameter : " << diameterBT(root) << endl;
    cout << "Optimised Diameter: " << OptDiameter(root).diameter << endl;

    cout << "height Of Tree : " << heightOfTree(root)<<endl;
    cout << "minimum depth: " << minDepth(root) << endl;

    cout << isSymmetric(root) <<endl;

    return 0;
}