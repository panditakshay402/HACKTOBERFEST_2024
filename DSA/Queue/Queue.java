package DSA.Queue;

public class Queue {
    private int[] queue;
    private int front, rear, capacity, size;

    // Constructor to initialize the queue
    public Queue(int capacity) {
        this.capacity = capacity;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Add an element to the queue
    public void enqueue(int element) {
        if (isFull()) {
            System.out.println("Queue is full. Cannot enqueue element.");
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = element;
        size++;
    }

    // Remove an element from the queue
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty. Cannot dequeue element.");
            return -1;
        }
        int element = queue[front];
        front = (front + 1) % capacity;
        size--;
        return element;
    }

    // Peek the front element
    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty.");
            return -1;
        }
        return queue[front];
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    public boolean isFull() {
        return size == capacity;
    }

    public static void main(String[] args) {
        Queue queue = new Queue(5);
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        System.out.println("Front element is " + queue.peek());
        queue.dequeue();
        System.out.println("Front element after dequeue is " + queue.peek());
    }
}
