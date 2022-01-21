#include <bits/stdc++.h>
using namespace std;
 
class Node {
    public: 
    int val;
    Node* left, *right;

    Node(int d){
        val =d;
        left=right = nullptr;
    }
};

Node * buildTree(){
    int d;
    cin>>d;

    if(d== -1){
        return nullptr;
    }

    Node *n = new Node(d);
    n->left = buildTree();
    n->right= buildTree();

    return n;
}


vector<int> sol;
vector<vector<int>> endvec;

void help(Node *root, int target){

    if(!root){
        return;
    }

    sol.push_back(root->val);
    int subSum = target - root->val;

    if(root->left == nullptr and root->right == nullptr){
        if(subSum == 0){
            endvec.push_back(sol);
            while(sol.size() !=1){
                sol.pop_back();
            }
            return;
        }else{
            sol.pop_back();
        }
    }

    help(root->left, subSum);
    help(root->right, subSum);

}

vector<vector<int>> pathSum(Node* root, int targetSum){
    // your code goes here
    help(root, targetSum);
    return endvec;
    
}

int main(){
    Node * root = buildTree();
    vector<vector<int>> myAns = pathSum(root, 22);

    for(auto x: myAns){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}