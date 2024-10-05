package DSA.LinkedList;

class SinglyLinkedList {
    Node head;

    // Inner class to represent a node
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            next = null;
        }
    }

    // Add a new node to the linked list
    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    // Display the linked list
    public void display() {
        if (head == null) {
            System.out.println("The list is empty.");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print( " -> "+temp.data );
            temp = temp.next;
        }
        System.out.println();
    }

    // Search for an element in the linked list
    public boolean search(int key) {
        Node temp = head;
        while (temp != null) {
            if (temp.data == key) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
        list.insert(10);
        list.insert(20);
        list.insert(30);
        System.out.print("Linked List: ");
        list.display();

        int searchElement = 20;
        if (list.search(searchElement)) {
            System.out.println(searchElement + " found in the list.");
        } else {
            System.out.println(searchElement + " not found in the list.");
        }
    }
}
