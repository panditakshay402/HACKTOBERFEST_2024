public class LinearSearch {

    public static int linearSearch(int[] arr, int element) {     //parameter are taken
        for (int i = 0; i < arr.length; i++) {                  //loop iterates through array
            if (arr[i] == element) {                            //compares each element with element
               return i;
            }
        }
        return -1;                                              //returns -1 if not found and index if found         
    }

    public static void main(String[] args) {
        int[] numbers = {8,14,65,23,19};
        int element = 14;
        int result = linearSearch(numbers, element);            //calls linear search function to search of the element
        
        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found.");
        }
    }
}
