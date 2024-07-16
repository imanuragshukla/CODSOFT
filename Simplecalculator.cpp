//Program to build a simple calculator

#include <iostream>

using namespace std;

int main() {
    char Operation;
    double Num1, Num2;

    cout << "Enter first number: ";
    cin >> Num1;

    cout << "Enter second number: ";
    cin >> Num2;

    cout << "Enter an operation (+, -, *, /): ";
    cin >> Operation;

    switch(Operation) {
        case '+':
            cout << Num1 << " + " << Num2 << " = " << (Num1 + Num2) << endl;
            break;
        case '-':
            cout << Num1 << " - " << Num2 << " = " << (Num1 - Num2) << endl;
            break;
        case '*':
            cout << Num1 << " * " << Num2 << " = " << (Num1 * Num2) << endl;
            break;
        case '/':
            if (Num2 != 0) {
                cout << Num1 << " / " << Num2 << " = " << (Num1 / Num2) << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        default:
            cout << "Invalid operation! Please enter one of +, -, *, /" << endl;
            break;
    }

    return 0;
}