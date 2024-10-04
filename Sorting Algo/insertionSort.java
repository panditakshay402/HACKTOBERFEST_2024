public class InsertionSort{
    public static void insertionsort(int[] arr){
        int n=arr.length;
        for(int i=1;i<n;i++){
            int key=arr[i];                     //current element to be inserted
            int j=i-1;                          //index of th elast element in the sorted portions

            while(j>=0 && arr[j]>key){          //move elements of the sorted portions that are greater than key to one position ahead of their current position
                arr[j+1]=arr[j];                //shift the element to the right 
                j--;                            //move to the previous element
            }
            arr[j+1]=key;                       //placing the key at its correct position
        }
    }
    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] numbers = {12, 11, 13, 5, 6};
        System.out.println("Original array:");
        printArray(numbers);
        insertionSort(numbers);
        System.out.println("Sorted array:");
        printArray(numbers);
    }
}

//original array: 12 11 13 5 6
//sorted array: 5 6 11 12 13