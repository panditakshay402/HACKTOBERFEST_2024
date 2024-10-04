package Sorting;
public class SelectionSort{
    public static void selectionsort(int[] arr){
        int n=arr.length;            //get the length of the array
        
        for(int i=0;i<n-1;i++){                 //outer loop
            int minIndex=i;                     //assuming the first index to be the smallest element
            for(int j=i+1;j<n;j++){             //inner loop
                if(arr[j]<arr[minIndex]){
                    minIndex=j;                 //updating minIndex if a smaller element is found
                }
            }

            int temp=arr[minIndex];             //Store the value of the smallest element in temp
            arr[minIndex]=arr[i];               //Replace the smallest element's position with the current element at index 'i'
            arr[i]=temp;                        //Place the smallest element in the current element's position
        }
    }
    public static void printArray(int[]arr){     //print the array elements
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        int[] numbers={64,25,12,22,11};         //print original array
        System.out.println("Original array:");
        printArray(numbers);
        selectionsort(numbers);                 //call the function
        System.out.println("Sorted array:");
        printArray(numbers);                    //print sorted array
    }
}

//original array:65 25 12 22 11
//sorted array: 11 12 22 25 64