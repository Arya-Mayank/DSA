#include <iostream>

using namespace std;

void applyTax(float income)
{
    income = income - (0.10 * income);
}

void applyTaxByReference(float &income)
{
    income = income - (0.10 * income);
}

int main()
{
    float income;
    cin >> income;

    applyTax(income); //pass by value, won't give right ans
    cout << "pass by value: " << income<<endl;

    applyTaxByReference(income); //pass by reference, right ans
    cout << "pass by reference: " << income;
    return 0;
}