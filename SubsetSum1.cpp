#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a subset of 'arr' with a sum equal to 'k'
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a vector 'prev' to store the previous row of the DP table
    vector<bool> prev(k + 1, false);

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++) {
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            // Store the result in the current DP table row for the current subproblem
            cur[target] = notTaken || taken;
        }

        // Update 'prev' with the current row 'cur' for the next iteration
        prev = cur;
    }

    // The final result is stored in prev[k]
    return prev[k];
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}
