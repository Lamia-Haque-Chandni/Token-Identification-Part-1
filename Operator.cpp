#include <iostream>
using namespace std;

int main()
{
    string expr;

    cout << "Enter the Expression: ";
    cin >> expr;

    cout << "Arithmetic operators in the Expression: ";
    for (char a : expr)
    {
        if (a == '+' || a == '-' || a == '*' || a == '/' || a=='%')
        {
            cout << "(" <<a <<")" << " ";
        }
    }

    cout << endl;

    return 0;
}
