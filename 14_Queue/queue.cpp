#include<iostream>
#include "queue.h"

using namespace std;

int main(){

    Queue q;

    q.push(7);
    q.push(8);
    q.push(5);
    q.push(1);
    q.push(17);
    q.pop();
    q.push(10);

    while(!q.empty()){
        cout << q.getFront() << endl;
        q.pop();
    }

    return 0;
}