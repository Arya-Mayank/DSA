#include <bits/stdc++.h>
#include "hashtable.h"

using namespace std;

int main()
{

    Hashtable<int> h;

    h.insert("mango", 5);
    h.insert("apple", 16);
    h.insert("banana", 82);
    h.insert("papaya", 10);
    h.insert("kiwi", 6);
    h.insert("strawberry", 16);
    h.insert("guava", 8);
    h.insert("litchi", 90);
    h.insert("dragonfruit", 100);

    h.print();

    h["New Fruit"] = 200;

    cout <<endl << "New fruit added : " << "price : " << h["New Fruit"] << endl;
    h["New Fruit"] += 20;
    cout << "updated price of new fruit : " << h["New Fruit"] << endl; 
    
    return 0;
}