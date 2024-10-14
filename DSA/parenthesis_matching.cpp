#include <iostream>
#include <string.h>
using namespace std;

const int stacksize = 3; // Define a constant for the array size

class parenthesis {
public:
    char demo[stacksize];
    int top;

public:
    parenthesis() {
        top = -1;
    }

    int empty() {
        return (top == -1);
    }

    int full() {
        return (top == stacksize - 1);
    }

    void push(char m) {
        if (full()) {
            cout << "Stack overflow, cannot push" << endl;
        }
        top = top + 1;
        demo[top] = m;
    }

    char pop() {
        if (empty()) {
            cout << "stack underflow, cannot pop" << endl;
        }
        return (demo[top--]);
    }

    char peek() {
        if (empty()) {
            cout << "stack empty" << endl;
        }
        return demo[top];
    }

    bool parenthesis_matched(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str.at(i) == '(' || str.at(i) == '{' || str.at(i) == '[') {
                push(str.at(i));
            } else if (str.at(i) == ')' || str.at(i) == '}' || str.at(i) == ']') {
                if ((str.at(i) == ')' && peek() == '(') || (str.at(i) == ']' && peek() == '[') || (str.at(i) == '}' && peek() == '{')) {
                    pop();
                } else {
                    cout << "Invalid string, parenthesis not matched" << endl;
                    return false;
                }
            } else {
                continue;
            }
        }
        return empty(); // Check if the stack is empty after processing the string
    }
};

int main() {
    parenthesis obj;
    string str;

    cout << "Enter the string expression " << endl;
    getline(cin, str);
    cout << (obj.parenthesis_matched(str) ? "Parenthesis matched" : "Parenthesis not matched") << endl;

    return 0;
}

