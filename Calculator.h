#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
#include <sstream>
#include <ctype.h>
#include "LinkedStack.h"

using namespace std;

class Calculator {
private:
    string expression;
    string pfexpr;
    string input;
    LinkedStack<int> I;
    LinkedStack<string> S;

public:
    Calculator(string);
    string postfix();
    int eval();
    void setExpr(string);
    string getExpr();
    bool isNumber(string);
    int precedence(string);
    int operate(int, int, string);
};

#endif // !CALCULATOR_H_
