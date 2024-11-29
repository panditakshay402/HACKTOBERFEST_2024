def bubble_sort(arr):
    """
    Sorts a list of numbers in ascending order using the Bubble Sort algorithm.
    
    The algorithm repeatedly steps through the list, compares adjacent elements,
    and swaps them if they are in the wrong order. It continues this process
    until the entire list is sorted.

    Parameters:
    arr (list): The list of numbers to be sorted. The function modifies the list in place.

    Example:
    >>> arr = [64, 34, 25, 12, 22, 11, 90]
    >>> bubble_sort(arr)
    >>> print(arr)
    [11, 12, 22, 25, 34, 64, 90]
    """
    
    n = len(arr)  # Get the length of the array

    # Outer loop for traversing the array multiple times
    for i in range(n):
        # Inner loop for comparing adjacent elements
        for j in range(0, n - i - 1):
            # Swap if the current element is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Swap the elements

# Example array to be sorted
arr = [64, 34, 25, 12, 22, 11, 90]

# Call the bubble_sort function to sort the array
bubble_sort(arr)

# Print the sorted array
print("Sorted array is:")
for i in range(len(arr)):
    print(arr[i])
