#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];  // Return already computed value
    
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);  // Store the result in dp array
    return dp[n];
}

int main() {
    int n = 10;
    vector<int> dp(n + 1, -1);  // Initialize dp array with -1
    cout << "Fibonacci of " << n << " is " << fibonacci(n, dp) << endl;
    return 0;
}
