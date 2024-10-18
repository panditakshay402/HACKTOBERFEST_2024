#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int curSum = 0;
    int maxSum = nums[0];
    
    for (auto i : nums) {
        if (curSum < 0) {
            curSum = 0;
        }
        curSum += i;
        maxSum = max(maxSum, curSum);
    }
    
    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "The maximum subarray sum is " << maxSubArray(nums) << endl;

    return 0;
}
