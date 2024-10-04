public class QuickSort {
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {                                               //find pivot element such that elements smaller than pivot are on left 
            int pivotIndex = partition(arr, low, high);                 //and elements greater than pivot are the right
            quickSort(arr, low, pivotIndex - 1);                        // Before pivot
            quickSort(arr, pivotIndex + 1, high);                       // After pivot
        }
    }


    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];                                          //choosing the rightmost element as pivot
        int i = (low - 1);                                              //pointer for the smaller element

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;                                                    //increment the smaller element pointer is cuurent element is smaller than or equal to the pivot
                int temp = arr[i];                                      //swap arr[i] and arr[j]
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];                                          // Swap the pivot element with the element at index (i + 1)
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;                                                   //return partitioning index
    }

    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] numbers = {10, 7, 8, 9, 1, 5};
        System.out.println("Original array:");
        printArray(numbers);
        quickSort(numbers, 0, numbers.length - 1);
        System.out.println("Sorted array:");
        printArray(numbers);
    }
}

//Original array:10 7 8 9 1 5 
//Sorted array:1 5 7 8 9 10 