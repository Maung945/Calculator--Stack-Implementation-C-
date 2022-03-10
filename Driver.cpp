#include <iostream>
#include <string.h>
#include <math.h>
#include "Calculator.h"

using namespace std;

int main() {
    cout << "[Myo Aung:} Calculator Enter 0 to exit the program." << endl;
    while(true) {
    string input;
    cout << "Enter an expression: ";
    getline(cin, input);
    if (input == "0") {
        break;
    }
    Calculator cal(input);
    cout << "Postfix expression: " << cal.postfix() << endl;
    cout << "Result: "  << cal.eval() << endl;
    }
    cout << "Thanks for using my calculator." << endl;
    return 0;
}