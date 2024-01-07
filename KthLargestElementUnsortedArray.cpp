#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
 priority_queue<int, vector<int>, greater<int>> minHeap; // Use min-heap
       
       // Step 1
       for(int i = 0; i < K; i++) {
           minHeap.push(arr[i]);
       }

       // Step 2
       for(int i = K; i <size; i++) {
           if (arr[i] > minHeap.top()) {
               minHeap.pop();
               minHeap.push(arr[i]);
           }
       }

       // Step 3
       int ans = minHeap.top();
       return ans;
}
