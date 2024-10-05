package DSA.Stack;

import java.util.EmptyStackException;

public class Stack {
    private int maxSize;
    private int top;
    private int[] stackArray;

    // Constructor to initialize the stack
    public Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1; // Represents an empty stack
    }

    // Push method to add an element
    public void push(int value) {
        if (top == maxSize - 1) {
            System.out.println("Stack is full.");
        } else {
            stackArray[++top] = value;
        }
    }

    // Pop method to remove an element
    public int pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        } else {
            return stackArray[top--];
        }
    }

    // Peek method to see the top element
    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        } else {
            return stackArray[top];
        }
    }

    // Check if stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    public static void main(String[] args) {
        Stack stack = new Stack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Top element is: " + stack.peek());
        System.out.println("Popped element is: " + stack.pop());
        System.out.println("Top element after pop: " + stack.peek());
    }
}

