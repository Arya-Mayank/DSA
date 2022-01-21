#include<iostream>
#include "list.h"

using namespace std;



int main(){

List l1;
l1.push_back(10);
l1.push_back(30);
l1.push_back(20);
l1.push_back(5);
// l1.push_back(11);

List l2;
l2.push_back(12);
l2.push_back(10);
l2.push_back(2);
l2.push_back(4);
l2.push_back(6);




// Node * start = alternateMerge(l1.begin(),l2.begin());

// while(start != nullptr){
//     cout << start->getData() << " -> ";
//     start = start->getNext();
// }

Node  * start = bubbleSort(l1.begin());
while(start != nullptr){
    cout << start->getData() << " -> ";
    start = start->getNext();
}

return 0;
}

