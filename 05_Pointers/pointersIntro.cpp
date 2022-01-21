#include <iostream>

using namespace std;

int main()
{
    // int variable
    int x = 10;

    //  printing address of x
    cout << "Address of x : " << &x << endl;

    // creating a pointer variable and storing value of address of x
    int *xptr = &x;
    cout << "Value of xptr: " << xptr << endl;

    cout << "Address of xptr: " << &xptr << endl;

    // creating a pointer to a pointer
    int **xxptr = &xptr;
    cout << "Value of xxptr: " << xxptr << endl;

    cout << endl << endl;

    // Dereference operator 
    cout <<"Value of x: "<< x << endl;
    cout << "Dereferencing xptr: "<< *xptr << endl;
    cout << "Double Dereferencing xxptr: "<< *(*xxptr) << endl;
    return 0;
}