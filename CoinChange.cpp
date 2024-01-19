
#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<long> prev(T + 1, 0);  // Create a vector to store the previous DP state

    // Initialize base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = 1;  // There is one way to make change for multiples of the first coin
        // Else condition is automatically fulfilled,
        // as the prev vector is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        vector<long> cur(T + 1, 0);  // Create a vector to store the current DP state
        for (int target = 0; target <= T; target++) {
            long notTaken = prev[target];  // Number of ways without taking the current coin

            long taken = 0;
            if (arr[ind] <= target)
                taken = cur[target - arr[ind]];  // Number of ways by taking the current coin
                
            cur[target] = notTaken + taken;  // Total number of ways for the current target
        }
        prev = cur;  // Update the previous DP state with the current state for the next coin
    }

    return prev[T];  // Return the total number of ways to make change for the target
}

int main() {
    vector<int> arr = {1, 2, 3};  // Coin denominations
    int target = 4;  // Target sum
    int n = arr.size();  // Number of coin denominations

    // Call the function to calculate and output the total number of ways to make change
    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;

    return 0;  // Return 0 to indicate successful program execution
}
