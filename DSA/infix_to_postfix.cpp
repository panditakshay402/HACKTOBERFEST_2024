#include <iostream>
#include <string>
using namespace std;

class mystack {
public:
    const int stacksize = 100;
    char a[100];
    int top;

    mystack() {
        top = -1;
    }

    void push(char x) {
        if (isfull()) {
            cout << "Stack is full, cannot push" << endl;
            return;
        }
        a[++top] = x;
    }

    char pop() {
        if (isempty()) {
            cout << "Stack is empty, cannot pop" << endl;
            return '\0'; 
        }
        return a[top--];
    }

    int isempty() {
        return (top == -1);
    }

    int isfull() {
        return (top == stacksize - 1);
    }

    char peek() {
        if (isempty()) {
            cout << "Stack is empty, cannot peek" << endl;
            return '\0'; 
        }
        return a[top];
    }

    bool isoperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    bool isoperand(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return -1;
    }

    string InfixtoPostfix(string infix) {
        string postfix;
        for (char ch : infix) {
            if (isoperand(ch)) {
                postfix += ch;
            } else if (ch == '(') {
                push(ch);
            } else if (ch == ')') {
                while (!isempty() && peek() != '(') {
                    postfix += pop();
                }
                pop(); // Pop the remaining '('
            } else {
                while (!isempty() && precedence(ch) <= precedence(peek())) {
                    postfix += pop();
                }
                push(ch);
            }
        }
        while (!isempty()) {
            postfix += pop();
        }
        return postfix;
    }
};

int main() {
    mystack obj;
    cout << "Enter the infix expression: ";
    string infix;
    getline(cin, infix);

    string postfix = obj.InfixtoPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
