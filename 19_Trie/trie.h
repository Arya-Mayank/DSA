#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    char ch;
    unordered_map<char, Node *> m;
    bool isTerminal;

    Node(char data)
    {
        ch = data;
        isTerminal = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    // insert in trie
    void insert(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m[ch] == 0)
            {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }

        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return false;
            }
            temp = temp->m[ch];
        }

        return temp->isTerminal;
    }

    void dfs(Node*temp, vector<string> &v, string word){

        if(temp->isTerminal){
            v.push_back(word);
        }

        if(temp->m.empty()){
            return;
        }

        for(auto p: temp->m){
            word.push_back(p.first);
            dfs(temp->m[p.first], v, word);
            word.pop_back();
        }

        return;
    }

    vector<string> find(string str){

        string word = "";
        vector<string> v;
        Node * temp = root;

        //reach till the prefix
        for(int i=0;i<str.length();i++){
            if(temp->m.count(str[i]) == 0){
                return v;
            }
            word.push_back(str[i]);
            temp= temp->m[str[i]];
        }
        
        //find remaining words
        dfs(temp, v, word);
        sort(v.begin(),v.end());

        return v;

    }


    vector<string> findPrefixStrings(vector<string> words, string prefix){

        Trie t;

        for(auto word: words){
            t.insert(word);
        }

        vector<string> res = t.find(prefix);
        return res;
    }

};



// vector<string> findPrefixStrings(vector<string> words, string prefix)
//     {
//         // your code goes here
//         Node *temp = root;
//         for (char ch : prefix)
//         {
//             temp = temp->m[ch];
//         }

//         vector<string> sol;

//         if (temp->isTerminal)
//         {
//             sol.push_back(prefix);
//         }

//         if(temp->m.empty()){
//             return sol;
//         }

//         unordered_map<char, Node *>::iterator it;

//         for (it = temp->m.begin(); it != temp->m.end(); it++)
//         {
//             string ans = prefix;
//             ans += it->first;

//             Node *n = it->second;

//             if (n->isTerminal)
//             {
//                 sol.push_back(ans);
//                 if (!n->m.empty())
//                 {
//                     vector<string> subAns = findPrefixStrings(words, ans);

//                     for (auto x : subAns)
//                     {
//                         sol.push_back(x);
//                     }

//                     // sol.pop_back();
//                 }
                
//             }
//             else
//             {
//                 vector<string> subAns = findPrefixStrings(words, ans);

//                 for (auto x : subAns)
//                 {
//                     sol.push_back(x);
//                 }
//                 sol.pop_back();
//             }
//         }

//         return sol;
//     }