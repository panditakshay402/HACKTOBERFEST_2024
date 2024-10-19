#include <iostream>
#include <vector>
using namespace std;

int SlidingWindow(vector<int>& nums, int goal) {
    if (goal < 0) {
        return 0;
    }
    int count = 0, i = 0, j = 0, sum = 0;
    while (j < nums.size()) {
        sum += (nums[j] % 2); // Add 1 if odd, 0 if even
        while (i < nums.size() && sum > goal) {
            sum -= (nums[i] % 2); // Subtract 1 if odd, 0 if even
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return SlidingWindow(nums, k) - SlidingWindow(nums, k - 1);
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = numberOfSubarrays(nums, k);
    cout << "Number of subarrays with exactly " << k << " odd numbers: " << result << endl;

    return 0;
}
