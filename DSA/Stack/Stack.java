package DSA.Stack;

import java.util.EmptyStackException;

/*
 * 
 * Stack: A stack is a linear data structure that follows the LIFO (Last In, First Out) principle. The most recent element added is the first to be removed. Think of it as a stack of books, where the book placed last is taken out first.

            Operations:
            push: Add an element to the top of the stack.
            pop: Remove the element from the top.
            peek: View the element at the top without removing it.
            isEmpty: Check if the stack is empty.
*/

public class Stack {
    private int[] stack;
    private int top;
    private int capacity;

    // Constructor to initialize the stack
    public Stack(int size) {
        stack = new int[size];
        capacity = size;
        top = -1;
    }

    // Push an element onto the stack
    public void push(int element) {
        if (isFull()) {
            System.out.println("Stack is full. Cannot push element.");
            return;
        }
        stack[++top] = element;
    }

    // Pop an element from the stack
    public int pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return stack[top--];
    }

    // Peek the top element
    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return stack[top];
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    public boolean isFull() {
        return top == capacity - 1;
    }

    public static void main(String[] args) {
        Stack stack = new Stack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.println("Top element is " + stack.peek());
        System.out.println("Removed Eleement "+stack.pop());
        System.out.println("Top element after pop is " + stack.peek());
    }
}

