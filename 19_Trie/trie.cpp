
#include "trie.h"

using namespace std;

int main(){

    Trie t;

    t.insert("he");
    t.insert("hello");

    cout << t.search("he") << endl << t.search("hell") << endl << t.search("hello") << endl;

    

    return 0;
}