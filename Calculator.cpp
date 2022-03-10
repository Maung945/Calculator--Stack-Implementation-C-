#include <iostream>
#include "Calculator.h"

// Constructor
Calculator::Calculator(string inputStr) : input(inputStr) {
    pfexpr = "";
}

// Setter Method for expression.
void Calculator::setExpr(string expr) {
    expression = expr;
}

// Getter Method for expression.
string Calculator::getExpr() {
    return expression;
}

// This method check for the dight, return false is there is digit otherwise true.
bool Calculator::isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// This method decides which operation is more important
int Calculator::precedence(string token) {
    if (token == "+" || token == "-")
        return 1;
    else if (token == "*" || token == "/")
        return 2;
    else if (token == "^")
        return 3;
    return 0;
}

// This function does the operation
int Calculator::operate(int n1, int n2, string op) {
    if (op == "+")
        return n2 + n1;
    else if (op == "-")
        return n2 - n1;
    else if (op == "*")
        return n2 * n1;
    else if (op == "/")
        return n2 / n1;
    else if (op == "%")
        return n2 % n1;
    else
        return pow(n2, n1);
}

string Calculator::postfix() {
    pfexpr = "";
    istringstream ss(input);
    string word;
    bool hasParenthesis = false;

    while (ss >> word) {
        if (isNumber(word)) {
            pfexpr += word + " ";
        }
        else if (word == "^") {
            S.push(word);
        }

        else if (word == "(") {
            S.push(word);
            hasParenthesis = true;
        }
        else if (word == ")") {
            while (S.top() != "(") {
                pfexpr += S.top() + " ";
                S.pop();
            }
            S.pop();
            hasParenthesis = false;
        }
        else {
            while (!S.empty() && (precedence(word) <= precedence(S.top()))) {
                pfexpr += S.top() + " ";
                S.pop();
            }
            S.push(word);
        }
    }
    while (!S.empty()) {
        pfexpr += S.top() + " ";
        S.pop();
    }
    if (hasParenthesis) {
        cout << "Invalid expression missing right parenthesis." << endl;
        pfexpr = "";
    }
    return pfexpr;
}

int Calculator::eval() {
    if (pfexpr.length() == 0) {
        return 0;
    }
    int result = 0;
    istringstream ss(pfexpr);
    string word;
    while (ss >> word) {
        if (isNumber(word)) {
            I.push(stoi(word));
        }
        else {
            int n1 = I.top();
            I.pop();
            int n2 = I.top();
            I.pop();
            result = operate(n1, n2, word);

            I.push(result);
        }
    }
    result = I.top();
    I.pop();
    return result;
}

