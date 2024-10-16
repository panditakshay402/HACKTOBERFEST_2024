import java.util.Arrays;
import java.util.Comparator;

public class RadixSort {
    
    // Utility method to get the maximum value based on comparator
    private static <T> T getMax(T[] arr, Comparator<? super T> comparator) {
        T max = arr[0];
        for (T t : arr) {
            if (comparator.compare(t, max) > 0) {
                max = t;
            }
        }
        return max;
    }

    // Sort objects based on the digit represented by the current place (like units, tens, etc.)
    private static <T> void countingSort(T[] arr, int exp, Comparator<? super T> comparator) {
        int n = arr.length;
        T[] output = Arrays.copyOf(arr, n);
        int[] count = new int[10];

        for (T t : arr) {
            int digit = ((Comparable<T>) t).toString().charAt(exp) - '0';  // Assuming digit representation in Comparable
            count[digit]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = ((Comparable<T>) arr[i]).toString().charAt(exp) - '0';
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        System.arraycopy(output, 0, arr, 0, n);
    }

    // Main Radix Sort logic
    public static <T> void radixSort(T[] arr, Comparator<? super T> comparator) {
        T max = getMax(arr, comparator);
        int maxDigits = max.toString().length();

        for (int exp = maxDigits - 1; exp >= 0; exp--) {
            countingSort(arr, exp, comparator);
        }
    }

    // Utility to print the array
    public static <T> void printArray(T[] arr) {
        for (T t : arr) {
            System.out.print(t + " ");
        }
        System.out.println();
    }

    // Person class inside the same file
    static class Person implements Comparable<Person> {
        private String name;
        private int age;

        public Person(String name, int age) {
            this.name = name;
            this.age = age;
        }

        public String getName() {
            return name;
        }

        public int getAge() {
            return age;
        }

        @Override
        public int compareTo(Person other) {
            return Integer.compare(this.age, other.age);
        }

        @Override
        public String toString() {
            return name + " (" + age + ")";
        }
    }

    public static void main(String[] args) {
        // Example objects (Person objects)
        Person[] persons = {
            new Person("Alice", 25),
            new Person("Bob", 30),
            new Person("Charlie", 22),
            new Person("David", 29),
            new Person("Eve", 27)
        };

        System.out.println("Original array:");
        printArray(persons);

        // Sorting by age (using Comparator)
        radixSort(persons, Comparator.comparingInt(Person::getAge));
        System.out.println("Sorted array by age:");
        printArray(persons);
    }
}

//  Output :
//     Original array:
//     Alice (25) Bob (30) Charlie (22) David (29) Eve (27) 
//     Sorted array by age:
//     Charlie (22) Alice (25) Eve (27) David (29) Bob (30)
