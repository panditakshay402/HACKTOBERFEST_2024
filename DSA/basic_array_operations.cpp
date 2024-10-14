#include <iostream>
using namespace std;

class arr {
public:
    int array[50];
    int n; // Size of the array

    // Constructor to initialize n
    arr() {
        n = 0;
    }

    // Method to take input for the array
    void input() {
        cout << "Enter the number of elements in the array: ";
        cin >> n;
        cout << "Enter the elements of the array:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }
    }

    // Method to sort the array using Bubble Sort
    void sort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        cout << "Your sorted array is: ";
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Method to search for an element using Linear Search
    int search(int x) {
        for (int i = 0; i < n; i++) {
            if (array[i] == x) {
                return i; // Element found at index i
            }
        }
        return -1; // Element not found
    }
};

// Main function to demonstrate sorting and searching
int main() {
    arr a;  // Create an object of class arr
    a.input();  // Input array elements

    a.sort();  // Sort the array

    int x;
    cout << "Enter the element to search: ";
    cin >> x;
    
    int result = a.search(x);  // Search for the element

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
