#include <iostream>
using namespace std;

const int queuesize = 100;

class Queue {
public:
    int items[queuesize];
    int front, rear;

    Queue(){ //constructor
        front=-1;
        rear=-1;
    }

    int isEmpty() {
        return (front == -1 && rear == -1) || (front > rear);
    }

    int isFull() {
        return rear == queuesize - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue " << endl;
        } else {
            items[++rear] = x;
        }
        if (front == -1)
            front = 0;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue " << endl;
            return 0;
        } else {
            return items[front++];
        }
    }
};

class Stack {
private:
    Queue q1, q2;

public:
    void push(int x) {
        q1.enqueue(x);
    }

    void transfer() {
        // Transfer all elements from q1 to q2 except the last element
        while (!q1.isEmpty()) {
            if (q1.front == q1.rear) {
                break;
            }
            q2.enqueue(q1.dequeue());
        }
    }

    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty, cannot pop" << endl;
            return 0;
        }

        // Move all elements from q2 back to q1
        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }

        return q1.dequeue();
    }

    void finalProcess() {
        transfer();
        cout << "Popped element: " << pop() << endl;
    }
};

int main() {
    cout << "Enter the number of elements you want to enter" << endl;
    int n;
    cin >> n;

    cout << "Enter the numbers" << endl;
    int x;

    Stack stack;

    for (int i = 0; i < n; i++) {
        cin >> x;
        stack.push(x);
    }

    cout << "Popping elements from the stack: " << endl;
    for (int i = 0; i < n; i++) {
        stack.finalProcess();
    }

    return 0;
}
