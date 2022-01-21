#include "trie.h"

using namespace std;

int main(){

    vector<string> words = {"hello", "he", "hell", "how", "hey"};
    // vector<string> input = {"hey", "hello", "he","how", "hell", "hellowy"};
    Trie t;

    for(auto word : words){
        t.insert(word);
    }

    vector<string> ans = t.findPrefixStrings(words, "h");
    for(auto x: ans){
        cout << x << endl;
    }

    

}