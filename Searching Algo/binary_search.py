def binary_search(arr, target, low, high):
    if low <= high:
        mid = (low + high) // 2  # Use integer division
        
        # Check if the target is at mid
        if arr[mid] == target:
            return mid
        
        # If the target is greater, ignore the left half
        elif arr[mid] < target:
            return binary_search(arr, target, mid + 1, high)
        
        # If the target is smaller, ignore the right half
        else:
            return binary_search(arr, target, low, mid - 1)
    
    # Target is not present in the array
    return -1

# Testing the binary search function
arr = [1, 2, 3, 4, 5, 6]
target = 3
low = 0
high = len(arr) - 1

result = binary_search(arr, target, low, high)

if result != -1:
    print(f"Target found at index {result}")
else:
    print("Target not found")
