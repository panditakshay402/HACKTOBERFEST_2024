package Sorting;
public class BubbleSort{
    public static void bubblesort(int[]arr){
        int n=arr.length;

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }

    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] numbers = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original array:");
        printArray(numbers);
        bubblesort(numbers);
        System.out.println("Sorted array:");
        printArray(numbers);
    }
}

//Original array:64 34 25 12 22 11 90 
//Sorted array:11 12 22 25 34 64 90 